#include "../include/mz_daemon.h"

namespace Meizhi
{
    int32_t MZDaemon::makeDaemon()
    {
        return daemon(0, 0); 
    }
}
