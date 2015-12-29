#include "mz_adapter.h"

//针对监听套接字的封装
BindAdapter::BindAdapter(EpollServer* pSvr) : _pEpollSvr(pSvr)
{
}