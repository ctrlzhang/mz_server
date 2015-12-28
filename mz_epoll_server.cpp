#include "mz_epoll_server.h"

//gloabl events
struct epoll_event events[100];

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

				//�����������ӵ�������ʱ��
			}
		}
		catch (...)
		{
			//log
		}
	}
}
