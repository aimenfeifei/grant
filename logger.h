#ifndef _G_LOGGER_H_
#define _G_LOGGER_H_

#include "global.h"

namespace grant{

class GLogEvent
{
public:
    std::string func;
    int line;
    std::string msg;
};

class GFormatter
{
public:
    std::shared_ptr<GFormatter> ptr;

};


class GAppender
{
public:
    std::shared_ptr<GAppender> ptr;
};

class GStdAppender
{
public:
    std::shared_ptr<GStdAppender> ptr;
};

class GFileAppender
{
public:
    std::shared_ptr<GFileAppender> ptr;
};


class GRANTAPI GLogger
{
public:
    std::shared_ptr<GLogger> ptr;

};





}

#endif // _G_LOGGER_H_
