#ifndef _MZ_LOG_H_
#define _MZ_LOG_H_

#include "mz_common.h"
#include "mz_singleton.h"

namespace Meizhi
{
    //forward declar
    class MZFile;

    class MZLog
    {
        public:
            void setLogFile(MZFile* p)
            {
                _pLogFile = p;
            }

            void setLogLevel(LogLevel lv)
            {
                _curLevel = lv;
            }

            void log(LogLevel level, const char* msg);        
    
        private:
            MZFile* _pLogFile;
            LogLevel _curLevel; 
    };

    typedef MZSingleTon<MZLog> SinMZLog; 
}

#endif
