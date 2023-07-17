#include <stdlib.h>

#include "EPollPoller.hpp"
#include "Poller.hpp"

Poller* Poller::newDefaultPoller(EventLoop* loop) {
    if (::getenv("MUDUO_USE_POLL")) {
        return nullptr; // 生成 poll 的实例
    }
    else {
        return new EPollPoller(loop); // 生成 epoll 的实例
    }
}