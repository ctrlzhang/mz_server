#include "mz_exception.h"
#include "execinfo.h"

MZ_Exception::MZ_Exception(const string& buffer) : _buffer(buffer), _code(0)
{
}

MZ_Exception::MZ_Exception(const string& buffer, int code) : _buffer(buffer), _code(code)
{
}

MZ_Exception::~MZ_Exception() throw()
{
}

const char* MZ_Exception::what() throw()
{
	return _buffer.c_str();
}

void MZ_Exception::getBacktrace()
{
	void* array[64];
	int nSize = backtrace(array, 64);
	
	char** symbols = backtrace_symbols(array, nSize);

	for (int i = 0; i < nSize; i++)
	{
		_buffer += symbols[i];
		_buffer += '\n';
	}

	//symbolsָ���ַ������飬��������ͨ��malloc�����, ʹ�������Ҫ�ͷ�
	free(symbols);
}