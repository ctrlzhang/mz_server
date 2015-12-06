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
}

#endif
