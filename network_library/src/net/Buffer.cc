#include <errno.h>
#include <sys/uio.h>
#include <unistd.h>

#include "Buffer.h"
#include "Logging.h"

const char Buffer::kCRLF[] = "\r\n";

ssize_t Buffer::readFd(int fd, int *saveErrno)
{
    char extrabuf[65536] = {0}; //64KB

    // 使用iovec分配两个连续的缓冲区
    struct iovec vec[2];
    const size_t writable = writableBytes();
    // 第一块缓冲区，指向可写空间
    vec[0].iov_base = begin() + writerIndex_;
    vec[0].iov_len = writable;
    // 第二块缓冲区，指向栈空间
    vec[1].iov_base = extrabuf;
    vec[1].iov_len = sizeof(extrabuf);

    const int iovcnt = (writable < sizeof(extrabuf)) ? 2 : 1;
    const ssize_t n = ::readv(fd, vec, iovcnt);

    if (n < 0)
    {
        *saveErrno = errno;
    }
    else if (n <= writable) // Buffer的可写缓冲区已经够存储读出来的数据了
    {
        writerIndex_ += n;
    }
    else // extrabuf里面也写入了n-writable长度的数据
    {
        writerIndex_ = buffer_.size();
        append(extrabuf, n - writable); 
    }
    return n;
}

// inputBuffer_.readFd表示将对端数据读到inputBuffer_中，移动writerIndex_指针
// outputBuffer_.writeFd表示将数据写入到outputBuffer_中，从readerIndex_开始，可以写readableBytes()个字节
ssize_t Buffer::writeFd(int fd, int *saveErrno)
{
    ssize_t n = ::write(fd, peek(), readableBytes());
    if (n < 0)
    {
        *saveErrno = errno;
    }
    return n;
}