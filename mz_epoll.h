#ifndef _H_EPOLL_H_
#define _H_EPOLL_H_

//封装epoll常见的操作
class Epoll
{
public:
	Epoll(bool bEt = true);
	~Epoll();

	//生成epoll
	void create(int max_connections);
	
	//添加监听句柄
	void add(int fd, long long data, uint32_t event);

	//修改句柄关注的事件
	void mod(int fd, long long data, uint32_t event);

	//从监听集合中删除句柄
	void del(int fd, long long data, uint32_t event);

	//等待时间
	int wait(int millseconds);

	//获取被触发的事件
	struct epoll_event& get(int index)
	{
		return _pEvents[index];
	}

protected:
	//实际控制epoll的操作
	void ctrl(int fd, long long data, uint32_t event, int op);

private:
	//epoll fd
	int _epoll_fd;

	//max connection num
	int _max_connections;

	//events
	struct epoll_event *_pEvents;

	//et mode
	bool _et;
};

#endif
