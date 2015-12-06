#ifndef _MZ_APPLICATION_H
#define _MZ_APPLICATION_H

#include "mz_common.h"
#include "mz_option_parser.h"
#include "mz_daemon.h"

#ifdef _WIN32
#include "windows.h"
#endif

namespace Meizhi
{
	//app slot
	typedef struct {
		//init
		pFunc g_app_pre_init;
		pFunc g_app_init;
		pFunc g_app_post_init;

		//start
		pFunc g_app_pre_start;
		pFunc g_app_start;
		pFunc g_app_post_start;

		//reload
		pFunc g_app_pre_reload;
		pFunc g_app_reload;
		pFunc g_app_post_reload;

		//stop
		pFunc g_app_pre_stop;
		pFunc g_app_stop;
		pFunc g_app_post_stop;
	
        //loop
        pFunc g_app_pre_loop;
        pFunc g_app_loop;
        pFunc g_app_post_loop;

    }stMzSlot, *stMzSlotPtr;

	/*
	**	业务框架类
	**	@desc 封装公共的处理逻辑
	**	@desc 命令行参数解析、守护进程启动、主逻辑
	*/
	class Application
	{
	public:
		Application() :_bStoped(false) {}
		~Application()
		{
			_bStoped = true;
		}

	public:
		//设置上下文
		void setContext(stMzContextPtr context)
		{
			_pContext = context;
		}

		//设置钩子
		void setSlot(stMzSlotPtr slot)
		{
			_pSlot = slot;
		}

	public:
		//运行
		int32_t run();

	private:
		//业务循环
		int32_t mainLoop();

		//定时任务处理
		int32_t dealTimer();

		//回调任务处理
		int32_t dealCallback();

		//信号处理
		int32_t dealSignal();

		//网络任务处理
		int32_t dealNetWork();

		//命令行参数解析
		int32_t parseOption();

		//设置为守护进程
		int32_t runAsDaemon(bool);

		//启动进程
		int32_t start();

		//初始化进程
		int32_t init();

		//终止进程
		int32_t stop();

		//重新加载进程配置
		int32_t reload();

		//获取当前程序状态
		bool isStoped() const
		{
			return _bStoped;
		}

		//获取程序上下文
		stMzContextPtr getContext() const { return _pContext; }

		//获取程序钩子
		stMzSlotPtr getSlot() const { return _pSlot; }

	private:
		//程序执行的上下文
		stMzContextPtr _pContext;
		stMzSlotPtr _pSlot;

		//程序当前状态
		bool _bStoped;
	};
}

#endif // !_MZ_APPLICATION_H
