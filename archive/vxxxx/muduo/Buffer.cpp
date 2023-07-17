#include "Buffer.hpp"

#include <errno.h>
#include <sys/uio.h>
#include <unistd.h>

ssize_t Buffer::readFd(int fd, int* saveErrno) {

    // 栈上的内存空间  64K
    char extrabuf[65536] = {0};

    struct iovec vec[2];

    // Buffer 底层缓冲区剩余的可写空间大小
    const size_t writable = writableBytes();

    vec[0].iov_base = begin() + writerIndex_;
    vec[0].iov_len = writable;

    vec[1].iov_base = extrabuf;
    vec[1].iov_len = sizeof(extrabuf);

    const int iovcnt = (writable < sizeof(extrabuf)) ? 2 : 1;

    // TODO: readv 函数说明
    const ssize_t n = ::readv(fd, vec, iovcnt);
    if (n < 0) {
        *saveErrno = errno;
    }

    // Buffer 的可写缓冲区足够存储读出来的数据了
    else if (n <= writable) {
        writerIndex_ += n;
    }

    // extrabuf 里面也写入了数据
    else {
        writerIndex_ = buffer_.size();

        // writerIndex_ 开始写 n - writable 大小的数据
        append(extrabuf, n - writable);
    }

    return n;
}

ssize_t Buffer::writeFd(int fd, int* saveErrno) {
    ssize_t n = ::write(fd, peek(), readableBytes());
    if (n < 0) {
        *saveErrno = errno;
    }
    return n;
}