#ifndef _G_LOGGER_H_
#define _G_LOGGER_H_

#include <iostream>
#include <memory> 

namespace grant{


struct GLogEvent
{
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

};

class GLoggerManager
{

};


}


#endif // _G_LOGGER_H
