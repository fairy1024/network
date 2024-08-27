#ifndef LOG_FILE_H
#define LOG_FILE_H

#include "FileUtil.h"

#include <mutex>
#include <memory>

class LogFile
{
public:
    LogFile(const std::string& basename,
            off_t rollSize,
            int flushInterval = 3,
            int checkEveryN = 1024);
    ~LogFile();

    void append(const char* data, int len);

    //创建新文件
    void flush();
    bool rollFile(); // 滚动日志

private:
    static std::string getLogFileName(const std::string& basename, time_t* now);
    void appendInLock(const char* data, int len);

    const std::string basename_;

    //滚动限制大小
    const off_t rollSize_;

    //刷新日志文件时间间隔 秒
    const int flushInterval_;

    //执行滚动的条目限制
    const int checkEveryN_;

    //条目数量
    int count_;

    std::unique_ptr<std::mutex> mutex_;

    //当前日志周期开始时间
    time_t startOfPeriod_;

    //上次滚动事件
    time_t lastRoll_;

    //上次刷新时间
    time_t lastFlush_;
    std::unique_ptr<FileUtil> file_;

    //文件滚动间隔
    const static int kRollPerSeconds_ = 60*60*24;
};

#endif // LOG_FILE_H