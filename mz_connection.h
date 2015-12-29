#ifndef _H_MZ_CONNECTION_H_
#define _H_MZ_CONNECTION_H_

#include "mz_adapter.h"

//�������ӹ���
class Connection
{
public:
	enum ConnectionType
	{
		E_TCP = 0,
		E_UDP = 1,
		E_BUS = 2,
	};

	//TCP������Ϣ
	Connection(BindAdapter *pBind, int lfd, int timeout, int connfd, const string& ip, short port);

	
};

//��ʾ���Ӷ���
class ConnectionList
{
public:
	//ָ��epoll server
	ConnectionList(EpollServer* pEpollSvr) : _pEpollSvr(pEpollSvr), _vConn(NULL) {}

	~ConnectionList()
	{
		if (_vConn)
		{
			delete[] _vConn;
			_vConn = NULL;
		}
	}

	//��ʼ�����Ӷ���
	void init(uint32_t size);

	//����Ψһ������id
	uint32_t genUniqId();

	//����µ����ӣ������ó�ʱʱ��
	void add(Connection *pConn, time_t timeout);

	//�������ӵĳ�ʱʱ��
	void refresh(Connection *pConn, time_t timeout);

	//������ӳ�ʱ
	void checkTimeout(time_t currentTime);

	//��ȡĳ�������׽����µ�����
	vector<ConnStatus> getConnStatus(int lfd);

	//��ȡĳ������
	Connection* get(uint32_t uid);

	//ɾ��ĳ������
	void del(uint32_t uid);

	//���Ӷ��д�С
	size_t size();

private:


};

#endif
