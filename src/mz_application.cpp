#include "include/mz_application.h"

namespace Meizhi
{
	int32_t Application::parseOption()
	{
        int32_t ret = MZOptionParser::parseOption(_pContext);
		cout << __FUNCTION__ << endl;
		return ret; 
	}

	int32_t Application::runAsDaemon(bool bDaemon)
	{
        if(bDaemon)
        {
            int32_t ret = MZDaemon::makeDaemon();
		    cout << __FUNCTION__ << endl;
		    return ret;
	    }
    
        return 0;
    }

	int32_t Application::dealCallback()
	{
		cout << __FUNCTION__ << endl;
		return 0;
	}

	int32_t Application::dealNetWork()
	{
		cout << __FUNCTION__ << endl;
		return 0;
	}

	int32_t Application::dealSignal()
	{
		cout << __FUNCTION__ << endl;
		return 0;
	}

	int32_t Application::dealTimer()
	{
		cout << __FUNCTION__ << endl;
		return 0;
	}

	int32_t Application::start()
	{
		return _pSlot->g_app_start(_pContext);
	}

	int32_t Application::stop()
	{
		return _pSlot->g_app_stop(_pContext);
	}

	int32_t Application::reload()
	{
		return _pSlot->g_app_reload(_pContext);
	}

	int32_t Application::init()
	{
		return _pSlot->g_app_init(_pContext);
	}

	int32_t Application::run()
	{
		int ret = 0;

		//参数解析
		ret = parseOption();

		//设置为守护进程
		ret = runAsDaemon(true);

		//初始化
		ret = init();

		//启动
		ret = start();

		//事件循环
		ret = mainLoop();

		return ret;
	}

	int32_t Application::mainLoop()
	{
		int iTask = 0;

		while (!_bStoped)
		{
			//定时任务
			iTask += dealTimer();

			//信号处理
			iTask += dealSignal();

			//回调任务
			iTask += dealCallback();

			//网络任务
			iTask += dealNetWork();

            //业务侧的循环任务
            iTask += _pSlot->g_app_loop(_pContext);

			if (0 == iTask)
			{
				//无任务时，休息200ms
				usleep(200000);
				SinMZLog::GetInstance()->log(LOG_LEVEL_DEBUG, "usleep 200ms");
			}

			iTask = 0;
		}

		return 0;
	}
}
