#include "../include/mz_log.h"
#include "../include/mz_file.h"
#include <string.h>

namespace Meizhi
{
    void MZLog::log(LogLevel level, const char* msg)
    {
        if(_pLogFile && level >= _curLevel)
        {
            _pLogFile->write(msg, strlen(msg));
        }
    }
}
