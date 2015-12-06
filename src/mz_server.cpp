#include "include/mz_application.h"
using namespace Meizhi;


//global var
stMzContext g_app_context;
stMzSlot g_app_slot;

int32_t mzAppInit(stMzContextPtr pContext)
{
	cout << __FUNCTION__ << endl;
	return 0;
}

int32_t mzAppReload(stMzContextPtr pContext)
{
	cout << __FUNCTION__ << endl;
	return 0;
}

int32_t mzAppStart(stMzContextPtr pContext)
{
	cout << __FUNCTION__ << endl;
	return 0;
}

int32_t mzAppStop(stMzContextPtr pContext)
{
	cout << __FUNCTION__ << endl;
	return 0;
}

int32_t mzAppLoop(stMzContextPtr pContext)
{
	cout << __FUNCTION__ << endl;
	return 0;
}

int main(int argc, char* argv[])
{
	g_app_context.app_argc = argc;
	g_app_context.app_argv = argv;

	g_app_slot.g_app_init = mzAppInit;
	g_app_slot.g_app_reload = mzAppReload;
	g_app_slot.g_app_start = mzAppStart;
	g_app_slot.g_app_stop = mzAppStop;
    g_app_slot.g_app_loop = mzAppLoop;

	Application mz_server;
	mz_server.setContext(&g_app_context);
	mz_server.setSlot(&g_app_slot);
	mz_server.run();
}
