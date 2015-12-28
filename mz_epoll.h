#ifndef _H_EPOLL_H_
#define _H_EPOLL_H_

//��װepoll�����Ĳ���
class Epoll
{
public:
	Epoll(bool bEt = true);
	~Epoll();

	//����epoll
	void create(int max_connections);
	
	//��Ӽ������
	void add(int fd, long long data, uint32_t event);

	//�޸ľ����ע���¼�
	void mod(int fd, long long data, uint32_t event);

	//�Ӽ���������ɾ�����
	void del(int fd, long long data, uint32_t event);

	//�ȴ�ʱ��
	int wait(int millseconds);

	//��ȡ���������¼�
	struct epoll_event& get(int index)
	{
		return _pEvents[index];
	}

protected:
	//ʵ�ʿ���epoll�Ĳ���
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
