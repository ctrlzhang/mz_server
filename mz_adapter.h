#ifndef _H_MZ_ADAPTER_H_
#define _H_MZ_ADAPTER_H_

#include <vector>
using namespace std;

//�Լ���socket�ķ�װ
class BindAdapter
{
public:
	enum AdapterConf
	{
		E_DEFAULT_QUEUE_SIZE = 10 * 1024, //Ĭ�϶��д�С10M
		E_DEFAULT_MAX_CONN = 1024,  //Ĭ��������
		E_DEFAULT_QUEUE_TIMEOUT = 60 * 1000, //Ĭ�϶��г�ʱʱ��
	};
	
	enum Order
	{
		E_ALLOW_DENY,
		E_DENY_ALLOW,
	};
	
	//ָ��epoll server
	BindAdapter(EpollServer* pSvr);

	//��������
	~BindAdapter();

	//set adapter name
	void setName(const string& name);

	//get adapter name
	string getName() const;

	int getQueueSize() const;

	void setQueueSize();

	//����Э������
	void setProtocolName(const string& name);

	//��ȡЭ������
	string getProtocolName();

	//�Ƿ����
	bool isOverload();

	//������Ϣ�ڶ����еĹ���ʱ��
	void setQueueTimeout(int t);

	int getQueueTimeout();

	//����ip �˿� Э�����͵�
	void setEndPoint(EndPoint& ep);
	void setEndPoint(const string& ep)

	//��ȡsocket
	Socket& getSocket();

	//�������������
	void setMaxConn(int max_conn);

	//��ȡ�������
	int getMaxConn();

	//��������ʱ��
	void setHeartBeatTime(int t);

	int getHeartBeatTime() const;

	//���ô���
	void setOrder(Order o);

	Order getOrder();

	//���ð�����ip
	void setAllowIps(const vector<string> &vec_allow_ips);

	vector<string> getAllowIps();

	//���ú�����ip
	void setDenyIps(const vector<string> &vec_deny_ips);

	vector<string> getDenyIps();

	//ip�Ƿ�����
	bool isIpAllow(const string& ip) const;

	//�Ƿ񳬹������������
	bool isOverMaxConn() const;

	//����������
	void decConnNum();

	//����������
	void incConnNum();

	//��ȡ��ǰ������
	int getCurConnNum();

	//��ȡ��������״̬
	vector<ConnStatus> getConnStatus();

	//��ȡepoll server
	EpollServer* getEpollServer();

	//ע��Э�������
	void setProtocolParser(const ProtocolFunctor& f);

	//��ȡЭ�������
	ProtocolFunctor& getProtocol();

	//�������󵽽��ն���
	void insertRecvQueue(const recv_queue::queue_type &vtRecvData, bool pushback = true);

	//��ȡ���ն��еĴ�С
	size_t getRecvBufferSize();

	//Ĭ�ϵ�Э�������
	static int echo_protocol(string& r, string& o);

	//Ĭ�ϵİ�ͷ����
	static int echo_header_filter(int i, string& o);

	//���ù����ڴ�
	void setShm(int key, int size);

	key_t getShmKey();

	size_t getShmSize();

	void initShm();

	struct BusCommu
	{
		string CommuKey;
		string c2sFifoName;
		string s2cFifoName;
		string c2sMmapName;
		string s2cMmapName;
		uint32_t c2sMmapSize;
		uint32_t s2cMmapSize;
	};

protected:
	friend class EpollServer;

	EpollServer* _pEpollSvr;

	ProtocolFunctor _pf;

	ProtocolFunctor _hf;

	//adapter name
	string _name;

	Socket _s;

	EndPoint _ep;

	int _maxConnNum;

	int _curConnNum;

	Order _order;

	vector<string> _vtAllow;

	vector<string> _vtDeny;

	//���ն���
	recv_queue _rbuffer;

	//���д�С
	int _queueSize;

	//��ʱʱ��
	int _timeout;

	//�ϴ���������ʱ��
	time_t _heartbeatTime;

	//�Ƿ�ʹ�ù����ڴ�
	bool _bUseShm;

	//�����ڴ����
	AdapterShmQueue _shmQueue;

private:
	//�Ƿ�ʹ�ù����ڴ�ͨ�����
	bool _bUseBusCommu;
	size_t _sizeBusCommu;
	string _BusCommuPath;
	map<string, BusCommu*> _mapBusCommu;
};

#endif
