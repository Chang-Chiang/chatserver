#include "Channel.hpp"

#include <sys/epoll.h>

#include "EventLoop.hpp"
#include "Logger.hpp"

const int Channel::kNoneEvent = 0;
const int Channel::kReadEvent = EPOLLIN | EPOLLPRI;
const int Channel::kWriteEvent = EPOLLOUT;

Channel::Channel(EventLoop* loop, int fd)
    : loop_(loop), fd_(fd), events_(0), revents_(0), index_(-1), tied_(false) {}

Channel::~Channel() {}

void Channel::handleEvent(Timestamp receiveTime) {
    // 是否绑定过
    if (tied_) {
        // 弱智能指针提升为强智能指针
        std::shared_ptr<void> guard = tie_.lock();
        if (guard) {
            handleEventWithGuard(receiveTime);
        }
    }
    else {
        handleEventWithGuard(receiveTime);
    }
}

void Channel::tie(const std::shared_ptr<void>& obj) {
    tie_ = obj;
    tied_ = true;
}

void Channel::remove() { loop_->removeChannel(this); }

void Channel::update() {
    // 通过 Channel 所属的 EventLoop, 调用 Poller 的相应方法, 注册 fd 的 events 事件
    loop_->updateChannel(this);
}

// 根据发生的具体事件调用相应的回调操作
void Channel::handleEventWithGuard(Timestamp receiveTime) {
    LOG_INFO("channel handleEvent revents:%d\n", revents_);

    // 发生异常, 断开连接
    if ((revents_ & EPOLLHUP) && !(revents_ & EPOLLIN)) {
        if (closeCallback_) {
            closeCallback_();
        }
    }

    // 发生错误, 处理错误
    if (revents_ & EPOLLERR) {
        if (errorCallback_) {
            errorCallback_();
        }
    }

    // 发生可读事件, 处理可读事件
    if (revents_ & (EPOLLIN | EPOLLPRI)) {
        if (readCallback_) {
            readCallback_(receiveTime);
        }
    }

    // 发生可写事件, 处理可写事件
    if (revents_ & EPOLLOUT) {
        if (writeCallback_) {
            writeCallback_();
        }
    }
}