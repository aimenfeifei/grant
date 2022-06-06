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








}



