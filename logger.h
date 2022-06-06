#ifndef _G_LOGGER_H_
#define _G_LOGGER_H_

#include "global.h"
#include <stringstream>

namespace grant{

struct GLogLevel
{
    enum Level {
        UNKNOW = 0, 
        TRACE,
        DEBUG,
        INFO,
        WARNING,
        ERROR,
        FATAL,
        MAX
    }; 

    static const char* toString(GLogLevel::Level level);
    static GLogLevel::Level fromString(const std::string& str);    
};


class GLogEvent
{
public:
    const char* file = nullptr;        // 文件名 
    int line;                          // 行号
    int threadid;
    int fiberid;
    std::string threadname;
    std::string fibername;
    std::string msg;

};
 
class GFormatter
{
public:
    typedef std::shared_ptr<GFormatter> ptr;
};


class GAppender
{
public:
    typedef std::shared_ptr<GAppender> ptr;

};

class GStdAppender
{
public:
    typedef std::shared_ptr<GStdAppender> ptr;
};

class GFileAppender
{
public:
   typedef std::shared_ptr<GFileAppender> ptr;
};


class GLogger
{
public:
    typedef std::shared_ptr<GLogger> ptr;

    GLogger();
    ~GLogger();

private:
    std::list<GAppender::ptr> appenders;
    
};

class GLoggerManager
{

};


}

#endif // _G_LOGGER_H_
