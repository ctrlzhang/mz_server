#ifndef _H_MZ_CONNECTION_H_
#define _H_MZ_CONNECTION_H_

#include "mz_adapter.h"

//服务连接管理
class Connection
{
public:
	enum ConnectionType
	{
		E_TCP = 0,
		E_UDP = 1,
		E_BUS = 2,
	};

	//TCP连接信息
	Connection(BindAdapter *pBind, int lfd, int timeout, int connfd, const string& ip, short port);

	
};

//表示连接队列
class ConnectionList
{
public:
	//指定epoll server
	ConnectionList(EpollServer* pEpollSvr) : _pEpollSvr(pEpollSvr), _vConn(NULL) {}

	~ConnectionList()
	{
		if (_vConn)
		{
			delete[] _vConn;
			_vConn = NULL;
		}
	}

	//初始化连接队列
	void init(uint32_t size);

	//生成唯一的连接id
	uint32_t genUniqId();

	//添加新的连接，并设置超时时间
	void add(Connection *pConn, time_t timeout);

	//更新连接的超时时间
	void refresh(Connection *pConn, time_t timeout);

	//检查连接超时
	void checkTimeout(time_t currentTime);

	//获取某个监听套接字下的连接
	vector<ConnStatus> getConnStatus(int lfd);

	//获取某个连接
	Connection* get(uint32_t uid);

	//删除某个连接
	void del(uint32_t uid);

	//连接队列大小
	size_t size();

private:


};

#endif
