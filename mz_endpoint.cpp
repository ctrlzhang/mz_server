#include "mz_endpoint.h"

EndPoint::EndPoint()
{
	_host = "0.0.0.0";
	_port = 0;
	_timeout = 3000;
	_isTcp = true;
	_grid = 0;
}

EndPoint::EndPoint(const string& host, int port, int timeout, bool isTcp/* =true */, int grid/* =0 */)
{
	_host = host;
	_port = port;
	_timeout = timeout;
	_isTcp = isTcp;
	_grid = grid;
}

EndPoint::EndPoint(const string& desc)
{
	parse(desc);
}

//浅拷贝构造函数
EndPoint::EndPoint(const EndPoint& ep)
{
	_host = ep._host;
	_port = ep._port;
	_timeout = ep._timeout;
	_isTcp = ep._isTcp;
	_grid = ep._grid;
}

//赋值函数
EndPoint& EndPoint::operator = (const EndPoint& ep)
{
	//通过地址来判断相等
	if (this != &ep)
	{
		_host = ep._host;
		_port = ep._port;
		_timeout = ep._timeout;
		_isTcp = ep._isTcp;
		_grid = ep._grid;
	}

	return *this;
}

bool EndPoint::operator == (const EndPoint& ep)
{
	if (this == &ep)
	{
		return true;
	}
	
	return (_host == ep._host && _port == ep._port && _timeout == ep._timeout && _grid == ep._grid && _isTcp == ep._isTcp);
}

void EndPoint::parse(const string& desc)
{
	_grid = 0;
	const string delim = " \t\n\r";
	string::size_type beg;
	string::size_type end = 0;

	beg = desc.find_first_not_of(delim, end);
	if (beg == string::npos)
	{
		throw MZ_Exception("parse error!");
	}

	end = desc.find_first_of(delim, beg);
	if (end == string::npos)
	{
		end = desc.length();
	}

	string tmp = desc.substr(beg, end);
	if (tmp == "tcp")
	{
		_isTcp = true;
	}
	else if (tmp == "udp")
	{
		_isTcp = false;
	}
	else
	{
		throw MZ_Exception("protocal error!");
	}

	desc = desc.substr(beg, end - beg);
	end = 0;

	while (true)
	{
		beg  = desc.find_first_not_of(delim, end);
		if (beg == string::npos)
		{
			break;
		}

		end = desc.find_first_of(delim, beg);
		if (end == string::npos)
		{
			end = desc.length();
		}

		//首先解析选项
		string option = desc.substr(beg, end - beg);
		if (option.length() != 2 && option[0] != '-')
		{
			throw MZ_Exception("option fail!");
		}

		//然后解析参数内容
		string argument = "";
		string::size_type arg_beg = desc.find_first_not_of(delim, end);
		if (arg_beg != string::npos && desc[arg_beg] != '-')
		{
			beg = arg_beg;
			end = desc.find_first_of(delim, beg);
			if (end == string::npos)
			{
				end = desc.length();
			}

			argument = desc.substr(beg, end - beg);
		}
		
		switch (option[1])
		{
		case 'h':
		{
			if (argument.empty())
			{
				throw MZ_Exception("host argument lost!");
			}

			_host = argument;
			break;
		}
		
		case 'p':
		{
			istringstream p(argument);
			if (!(p >> _port) || !p.eof() || _port < 0 || _port > 65535)
			{
				throw MZ_Exception("port argument error!");
			}
			break;
		}

		case 't':
		{
			istringstream t(argument);
			if (!(t >> _timeout) || !t.eof())
			{
				throw MZ_Exception("timeout argument error!");
			}
			break;
		}

		case 'g':
		{
			istringstream g(argument);
			if (!(g >> _grid) || !g.eof())
			{
				throw MZ_Exception("grid argument error!");
			}
			break;
		}

		default:
		{
		}
		}
	}//end while

	if (_host.empty())
	{
		throw MZ_Exception("host is empty!");
	}
	else if(_host == "")
	{
		_host = "0.0.0.0";
	}
}//end parse