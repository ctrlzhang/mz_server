#include "mz_epoll_server.h"

EpollServer::EpollServer() : _bTerminated(false), _bStarted(false), _bCreated(false), _bCanLog(true)
{
	
}

EpollServer::~EpollServer()
{
	map<int, BindAdapterPtr>::iterator it = _listeners.begin();
	while (it != _listeners.end())
	{
		::close(it->first);
		++it;
	}

	_listeners.clear();
}

map<int, BindAdapterPtr> EpollServer::getListeners()
{
	return _listeners;
}

void EpollServer::debug(const string& s)
{
	if (_bCanLog)
	{
		SinMZLog::GetInstance()->log(LOG_LEVEL_DEBUG, s.c_str());
	}
}

void EpollServer::info(const string& s)
{
	if (_bCanLog)
	{
		SinMZLog::GetInstance()->log(LOG_LEVEL_INFO, s.c_str()
	}
}

void EpollServer::error(const string& s)
{
	if (_bCanLog)
	{
		SinMZLog::GetInstance()->log(LOG_LEVEL_ERROR, s.c_str());
	}
}

//绑定socket前，需校验之前是否已经绑定过
int EpollServer::bind(BindAdapterPtr p)
{
	map<int, BindAdapterPtr>::iterator it = _listeners.begin();

	while (it != _listeners.end())
	{
		if (it->second->getName() == p->getName())
		{
			throw MZ_Exception("bind error");
		}

		++it;
	}

	const EndPoint ep = p->getEndPoint();
	Socket s = p->getSocket();
	
	bind(ep, s);

	_listeners[s.getfd()] = p;

	return s.getfd();
}

void EpollServer::bind(const EndPoint& ep, Socket& s)
{
	int type = ep.
}



EpollServer::process()
{
	int eventNum = epoll_wait(epoll_fd, events, 100, -1);
	for (int i = 0; i < eventNum; i++)
	{
		try:
		{
			epoll_event ev = events[i];
			int fd = ev.data.fd;
			if (fd == listen_fd)
			{
				accept(listen_fd);
			}
			else
			{
				if (ev.events & EPOLLIN)
				{
					recv();
				}

				if (ev.events & EPOLLOUT)
				{
					send();
				}

				//更新这条连接的请求处理时间
			}
		}
		catch (...)
		{
			//log
		}
	}
}
