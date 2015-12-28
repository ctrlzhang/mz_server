#include "mz_epoll.h"

Epoll::Epoll(bool bEt)
{
	_et = bEt;
	_pEvents = NULL;
	_epoll_fd = -1;
}

Epoll::~Epoll()
{
	if (_pEvents != NULL)
	{
		delete[] _pEvents;
		_pEvents = NULL;
	}

	//must close _epoll_fd£¬ in order to prevent memory leak 
	if (_epoll_fd > 0)
	{
		close(_epoll_fd);
	}
}

void Epoll::ctrl(int fd, long long data, uint32_t events, int op)
{
	struct epoll_event ev;
	ev.data.u64 = data;
	if (_et)
	{
		ev.events = events | EPOLLET;
	}
	else
	{
		ev.events = events | EPOLLLT;
	}

	epoll_ctl(_epoll_fd, op, fd, &ev);
}

void Epoll::create(int max_connections)
{
	_max_connections = max_connections;
	_epoll_fd = epoll_create(_max_connections + 1);
	if (_pEvents != NULL)
	{
		delete[] _pEvents;
	}
	
	_pEvents = new epoll_event[_max_connections + 1];
}

void Epoll::add(int fd, long long data, uint32_t events)
{
	ctrl(fd, data, events, EPOLL_CTL_ADD);
}

void Epoll::mod(int fd, long long data, uint32_t events)
{
	ctrl(fd, data, events, EPOLL_CTL_MOD);
}

void Epoll::del(int fd, long long data, uint32_t events)
{
	ctrl(fd, data, events, EPOLL_CTL_DEL);
}

int Epoll::wait(int millseconds)
{
	return epoll_wait(_epoll_fd, _pEvents, _max_connections+1, millseconds);
}