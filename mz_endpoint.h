#ifndef _H_ENDPOINT_H_
#define _H_ENDPOINT_H_

class EndPoint
{
public:
	EndPoint();

	//ip port timeout
	EndPoint(const string& host, int port, int timeout, bool isTcp=true, int grid=0);
	
	//
	EndPoint(const string& desc);

	//copy construct
	EndPoint(const EndPoint& ep);

	EndPoint& operator=(const EndPoint& ep);

	bool operator == (const EndPoint& ep);

	//set ip
	void setHost(const string& host)
	{
		_host = host;
	}

	string getHost() const
	{
		return _host;
	}

	//set port
	void setPort(int port)
	{
		_port = port;
	}

	int getPort() const 
	{
		return _port;
	}

	//set timeout
	void setTimeout(int timeout)
	{
		_timeout = timeout;
	}

	int getTimeout() const
	{
		return _timeout;
	}

	//whether tcp or not
	bool isTcp()
	{
		return _isTcp;
	}

	void setTcp(bool status)
	{
		_isTcp = status;
	}

	//grid status
	void setGrid(int grid)
	{
		_grid = grid;
	}

	int getGrid() const
	{
		return _grid;
	}

	//whether local unix socket
	bool isUnixLocal() const
	{
		return _port == 0;
	}

	//×ª»»Îª×Ö·û´®ÃèÊö
	string toString()
	{
		ostringstream os;
		os << (isTcp() ? "tcp" : "udp") << " -h "<< _host << " -p " << _port << " -t "<< _timeout;
		if (_grid != 0)
		{
			os << " -g " << _grid;
		}

		return os.str();
	}

	void parse(const string& desc);

private:
	string _host;
	int _port;
	int _timeout;
	bool _isTcp;
	int _grid;
};

#endif
