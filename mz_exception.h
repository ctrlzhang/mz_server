#ifndef _H_EXCEPTION_H_
#define _H_EXCEPTION_H_

#include <exception>

class MZ_Exception : public exception
{
public:
	explicit MZ_Exception(const string& buffer);
	
	MZ_Exception(const string& buffer, int err);
	
	virtual ~MZ_Exception() throw();

	virtual const char* what() throw();

	int getErrCode()
	{
		return _code;
	}

private:
	void getBacktrace();

private:
	//�쳣��Ϣ
	string _buffer;
	
	//������
	int _code;
};

#endif