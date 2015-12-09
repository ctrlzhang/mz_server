#ifndef _MZ_COMMON_H_
#define _MZ_COMMON_H_

#include <stdint.h>
#include <unistd.h>
#include <iostream>
using namespace std;

namespace Meizhi
{
	//contexts
	typedef struct {
		int app_argc;
		char** app_argv;
	}stMzContext, *stMzContextPtr;

	//pFunc type
	typedef int32_t (*pFunc) (stMzContextPtr);
    
    //open mode
    enum OpenMode
    {
        OPEN_MODE_R,
        OPEN_MODE_W,
        OPEN_MODE_RW,
        OPEN_MODE_APP,
    };

    //log level
    enum LogLevel
    {
        LOG_LEVEL_INFO,
        LOG_LEVEL_DEBUG,
        LOG_LEVEL_WARN,
        LOG_LEVEL_ERROR,
    };
}

#endif
