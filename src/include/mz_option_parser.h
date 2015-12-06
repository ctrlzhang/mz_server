#ifndef _MZ_OPTION_H_
#define _MZ_OPTION_H_

#include "mz_common.h"
#include "cmdline.h"

namespace Meizhi
{
	class MZOptionParser
	{
	private:
		//不允许声明实例
		MZOptionParser() {};
		~MZOptionParser() {};

	public:
		//解析命令行参数
		static int32_t parseOption(stMzContextPtr pContext);
	};
}

#endif
