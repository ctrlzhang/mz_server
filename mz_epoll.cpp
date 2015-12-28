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

	if (_epoll_fd > 0)
	{
		close(_epoll_fd);
	}
}

void Epoll::ctrl(int fd, long long data, uint32_t event, int op)
{
	struct epoll_event ev;
	ev.data.u64 = data;
}