#ifndef _H_MZ_EPOLL_SVR_H_
#define _H_MZ_EPOLL_SVR_H_

#include "mz_log.h"
#include "mz_epoll.h"
#include "mz_connection.h"
#include "mz_adapter.h" 
#include "mz_message_queue.h"
#include "mz_exception.h"
#include "mz_endpoint.h"

//服务端逻辑封装
class EpollServer
{
public:
	EpollServer();
	~EpollServer();

	//获取监听套接字
	map<int, BindAdapterPtr> getListeners();

	//record log
	void debug(const string& s);
	void info(const string& s);
	void error(const string& s);

	//bind listen fd
	int bind(BindAdapterPtr p);

	//绑定
	void bind(const EndPoint& ep, Socket& s);

	//业务处理逻辑
	void process();

private:
	//epoll's operation object
	Epoll _epoll;

	//server status
	bool _bTerminated;

	//epoll has created
	bool _bCreated;

	//server has start
	bool _bStarted;

	//server debug mode
	bool _bCanLog;

	//connection list
	ConnectionList _list;

	//消息队列
	MessageQueue _msgQueue;

	//监听的socket
	map<int, BindAdapterPtr> _listeners;
};

#endif
