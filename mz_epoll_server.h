#ifndef _H_MZ_EPOLL_SVR_H_
#define _H_MZ_EPOLL_SVR_H_

#include "mz_log.h"
#include "mz_epoll.h"
#include "mz_connection.h"
#include "mz_adapter.h" 
#include "mz_message_queue.h"
#include "mz_exception.h"
#include "mz_endpoint.h"

//������߼���װ
class EpollServer
{
public:
	EpollServer();
	~EpollServer();

	//��ȡ�����׽���
	map<int, BindAdapterPtr> getListeners();

	//record log
	void debug(const string& s);
	void info(const string& s);
	void error(const string& s);

	//bind listen fd
	int bind(BindAdapterPtr p);

	//��
	void bind(const EndPoint& ep, Socket& s);

	//ҵ�����߼�
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

	//��Ϣ����
	MessageQueue _msgQueue;

	//������socket
	map<int, BindAdapterPtr> _listeners;
};

#endif
