#include "logger.h"

namespace grant{

const char* GLogLevel::toString(GLogLevel::Level level){
    switch (level){
#define GDEF(l) \
    case GLogLevel::l : \
        return #l;   \
        break; 

        GDEF(TRACE);
        GDEF(DEBUG);
        GDEF(INFO);
        GDEF(WARNING);
        GDEF(ERROR);
        GDEF(FATAL);
#undef
    default:
        return "UNKNOW";
    }
    return "UNKOWN";
}

GLogLevel::Level GLogLevel::fromString(const std::string& str){
#define GDEF(l) \
    if(str == #l) \
        return GLogLevel::l;

    GDEF(TRACE);
    GDEF(DEBUG);
    GDEF(INFO);
    GDEF(WARNING);
    GDEF(ERROR);
    GDEF(FATAL);
    return GLogLevel::UNKNOW;
#undef
}




GLogger::GLogger(const std::string name):root(nullptr),
    name(name),
    level(GLogLevel::TRACE){
}


void GLogger::log(GLogLevel::Level level, GLogEvent::ptr event){

}
void GLogger::trace(GLogEvent::ptr event){
    log(GLogLevel::TRACE, event);
}
void GLogger::debug(GLogEvent::ptr event){
    log(GLogLevel::DEBUG, event);
}
void GLogger::info(GLogEvent::ptr event){
    log(GLogEvent::INFO, event);
}
void GLogger::warning(GLogEvent::ptr event){
    log(GLogEvent::WARNING, event);
}
void GLogger::error(GLogEvent::ptr, event){
    log(GLogEvent::ERROR, event);
}
void GLogger::fatal(GLogEvent::ptr, event){
    log(GLogEvent::FATAL, event);
}


void GLogger::setLevel(GLogLevel::Level l){
    level = l;
}
GLogLevel::Level GLogger::getLevel(){
    return level;
}
void GLogger::addAppender(GAppender::ptr appender){
    appenders.emplace_back(appender);
}
void GLogger::delAppender(GAppender::ptr appender){
    for (auto it = appenders.beign(); it != appenders.end(); ++ir){
        if(*it == appender){
            appenders.erase(it); 
            return;
        }
    }
}
void GLogger::clearAppender(){
    appenders.clear();
}
void GLogger::setFormatter(GFormatter::ptr f){
    formatter = f;
    for (auto it : appenders){
        it->setFormatter(f);
    }
}
void GLogger::setFormatter(const std::string& pattern){
    
}


}



