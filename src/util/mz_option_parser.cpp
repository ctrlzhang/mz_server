#include "../include/mz_option_parser.h"
#include "unistd.h"
#include <string.h>

namespace Meizhi
{
	int32_t MZOptionParser::parseOption(stMzContextPtr pContext)
	{
        cmdline::parser cmdParser;
        cmdParser.add<string>("host", 'h', "host name");
        cmdParser.add<int32_t>("port", 'p', "port number");
        cmdParser.add<string>("log", '\0', "log file path");

        cmdParser.parse_check(pContext->app_argc, pContext->app_argv);

        cout<<cmdParser.get<string>("host")<<endl
		    <<cmdParser.get<int32_t>("port")<<endl
		    <<cmdParser.get<string>("log")<<endl;

        return 0;
	}
}
