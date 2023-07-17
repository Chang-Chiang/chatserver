#include "Thread.hpp"

#include <semaphore.h>
#include <stdio.h> /* snprint */

#include "CurrentThread.hpp"

#define BUFFER_SIZE 32

std::atomic_int Thread::numCreated_(0);

Thread::Thread(ThreadFunc func, const std::string& name)
    : started_(false), joined_(false), tid_(0), func_(std::move(func)), name_(name) {
    setDefaultName();
}
 
Thread::~Thread() {
    if (started_ && !joined_) {
        // thread 类提供的设置分离线程的方法
        thread_->detach(); 
    }
}

void Thread::start() {
    started_ = true;
    sem_t sem;
    sem_init(&sem, false, 0);

    // 开启线程
    thread_ = std::shared_ptr<std::thread>(new std::thread([&]() {
       
        // 获取线程的 tid 值
        tid_ = CurrentThread::tid();
        sem_post(&sem);

        // 开启一个新线程, 专门执行该线程函数
        func_();
    }));

    // 这里必须等待获取上面新创建的线程的 tid 值
    sem_wait(&sem);
}

void Thread::join() {
    joined_ = true;
    thread_->join();
}

void Thread::setDefaultName() {
    int num = ++numCreated_;
    if (name_.empty()) {
        char buf[BUFFER_SIZE] = {0};
        snprintf(buf, sizeof(buf), "Thread%d", num);
        name_ = buf;
    }
}