#ifndef BUFFER_H
#define BUFFER_H

#include <vector>
#include <string>
#include <algorithm>


class Buffer
{
public:
    static const size_t kCheapPrepend = 8;
    static const size_t kInitialSize = 1024;    

    explicit Buffer(size_t initialSize = kInitialSize)
        :   buffer_(kCheapPrepend + initialSize),
            readerIndex_(kCheapPrepend),
            writerIndex_(kCheapPrepend)
        {}
    
    //现使用空间
    size_t readableBytes() const { return writerIndex_ - readerIndex_; }   
    size_t writableBytes() const { return buffer_.size() - writerIndex_; }
    size_t prependableBytes() const { return readerIndex_; }

    // 可读数据的起始地址
    const char* peek() const
    {
        return begin() + readerIndex_;
    }

    //读取数据后复位操作:地址
    void retrieveUntil(const char *end)
    {
        retrieve(end - peek());
    }
    
    //读取数据后复位操作:长度
    void retrieve(size_t len)
    {
        if (len < readableBytes())
        {
            readerIndex_ += len;
        }
        else
        {
            retrieveAll();
        }
    }

    //全部读完初始化
    void retrieveAll()
    {
        readerIndex_ = kCheapPrepend;
        writerIndex_ = kCheapPrepend;
    }

    // DEBUG:inspect buffer data
    std::string GetBufferAllAsString()
    {
        size_t len = readableBytes();
        std::string result(peek(), len);
        return result;
    }

    //读取数据
    std::string retrieveAllAsString()
    {   
        return retrieveAsString(readableBytes());
    }

    std::string retrieveAsString(size_t len)
    {
        std::string result(peek(), len);
        retrieve(len); 
        return result;
    }

    //保证空间够用
    void ensureWritableBytes(size_t len)
    {
        if (writableBytes() < len)
        {
            // 扩容函数
            makeSpace(len);
        }
    }

    //添加数据
    // string::data() 转换成字符数组，但是没有 '\0'
    void append(const std::string &str)
    {
        append(str.data(), str.size());
    }

    void append(const char *data, size_t len)
    {
        ensureWritableBytes(len);
        std::copy(data, data+len, beginWrite());
        writerIndex_ += len;
    }

    const char* findCRLF() const
    {
        // FIXME: replace with memmem()?
        const char* crlf = std::search(peek(), beginWrite(), kCRLF, kCRLF+2);
        return crlf == beginWrite() ? NULL : crlf;
    }

    char* beginWrite()
    {
        return begin() + writerIndex_;
    }

    const char* beginWrite() const
    {
        return begin() + writerIndex_;
    }

    // 从fd上读取数据
    ssize_t readFd(int fd, int *saveErrno);
    // 通过fd发送数据
    ssize_t writeFd(int fd, int *saveErrno);
    
private:
    char* begin()
    {
        // 获取buffer_起始地址
        return &(*buffer_.begin());
    }

    const char* begin() const
    {
        return &(*buffer_.begin());
    }

    //扩容操作
    void makeSpace(int len)
    {
        // 整个buffer都不够用
        if (writableBytes() + prependableBytes() < len + kCheapPrepend)
        {
            buffer_.resize(writerIndex_ + len);
        }
        else // 整个buffer够用，将后面移动到前面继续分配
        {
            size_t readable = readableBytes();
            std::copy(begin() + readerIndex_,
                    begin() + writerIndex_,
                    begin() + kCheapPrepend);
            readerIndex_ = kCheapPrepend;
            writerIndex_ = readerIndex_ + readable;
        }
    }

    std::vector<char> buffer_;
    size_t readerIndex_;
    size_t writerIndex_;
    static const char kCRLF[];
};

#endif // BUFFER_H