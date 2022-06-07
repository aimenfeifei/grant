#ifndef _G_LOGGER_H_
#define _G_LOGGER_H_

#include "global.h"
#include <sstream>
#include <memory>

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
    typedef std::shared_ptr<GLogEvent> ptr;

private:
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

private:
    
};


class GAppender
{
public:
    typedef std::shared_ptr<GAppender> ptr;

protected:
    GFormatter::ptr formatter;
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
    GLogger(const std::string& name = "root");

    void log(GLogLevel::Level, GLogEvent::ptr event);
    void trace(GLogEvent::ptr event);
    void debug(GLogEvent::ptr event);
    void info(GLogEvent::ptr event);
    void warning(GLogEvent::ptr event);
    void error(GLogEvent::ptr event);
    void fatal(GLogEvent::ptr event);

    std::string getName() const {return name;}

    void setLevel(GLogLevel::Level level);
    GLogLevel::Level getLevel();
    void addAppender(GAppender::ptr appender);
    void delAppender(GAppender::ptr appender);
    void clearAppender();
    void setFormatter(GFormatter::ptr formatter);
    void setFormatter(const std::string& pattern);

private:
    GLogger::ptr root;
    std::string name;
    GLogLevel::Level level;
    GFormatter::ptr formatter;
    std::list<GAppender::ptr> appenders;
};

class GLoggerManager
{

};


}

#endif // _G_LOGGER_H_
