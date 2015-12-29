#ifndef _H_MZ_ADAPTER_H_
#define _H_MZ_ADAPTER_H_

#include <vector>
using namespace std;

//对监听socket的封装
class BindAdapter
{
public:
	enum AdapterConf
	{
		E_DEFAULT_QUEUE_SIZE = 10 * 1024, //默认队列大小10M
		E_DEFAULT_MAX_CONN = 1024,  //默认连接数
		E_DEFAULT_QUEUE_TIMEOUT = 60 * 1000, //默认队列超时时间
	};
	
	enum Order
	{
		E_ALLOW_DENY,
		E_DENY_ALLOW,
	};
	
	//指定epoll server
	BindAdapter(EpollServer* pSvr);

	//析构函数
	~BindAdapter();

	//set adapter name
	void setName(const string& name);

	//get adapter name
	string getName() const;

	int getQueueSize() const;

	void setQueueSize();

	//设置协议名称
	void setProtocolName(const string& name);

	//获取协议名称
	string getProtocolName();

	//是否过载
	bool isOverload();

	//设置消息在队列中的过期时间
	void setQueueTimeout(int t);

	int getQueueTimeout();

	//设置ip 端口 协议类型等
	void setEndPoint(EndPoint& ep);
	void setEndPoint(const string& ep)

	//获取socket
	Socket& getSocket();

	//设置最大连接数
	void setMaxConn(int max_conn);

	//获取最大连接
	int getMaxConn();

	//设置心跳时间
	void setHeartBeatTime(int t);

	int getHeartBeatTime() const;

	//设置次序
	void setOrder(Order o);

	Order getOrder();

	//设置白名单ip
	void setAllowIps(const vector<string> &vec_allow_ips);

	vector<string> getAllowIps();

	//设置黑名单ip
	void setDenyIps(const vector<string> &vec_deny_ips);

	vector<string> getDenyIps();

	//ip是否被允许
	bool isIpAllow(const string& ip) const;

	//是否超过了最大连接数
	bool isOverMaxConn() const;

	//减少连接数
	void decConnNum();

	//增加连接数
	void incConnNum();

	//获取当前连接数
	int getCurConnNum();

	//获取所有连接状态
	vector<ConnStatus> getConnStatus();

	//获取epoll server
	EpollServer* getEpollServer();

	//注册协议解析器
	void setProtocolParser(const ProtocolFunctor& f);

	//获取协议解析器
	ProtocolFunctor& getProtocol();

	//插入请求到接收队列
	void insertRecvQueue(const recv_queue::queue_type &vtRecvData, bool pushback = true);

	//获取接收队列的大小
	size_t getRecvBufferSize();

	//默认的协议解析类
	static int echo_protocol(string& r, string& o);

	//默认的包头处理
	static int echo_header_filter(int i, string& o);

	//设置共享内存
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

	//接收队列
	recv_queue _rbuffer;

	//队列大小
	int _queueSize;

	//超时时间
	int _timeout;

	//上次心跳发送时间
	time_t _heartbeatTime;

	//是否使用共享内存
	bool _bUseShm;

	//共享内存队列
	AdapterShmQueue _shmQueue;

private:
	//是否使用共享内存通信组件
	bool _bUseBusCommu;
	size_t _sizeBusCommu;
	string _BusCommuPath;
	map<string, BusCommu*> _mapBusCommu;
};

#endif
