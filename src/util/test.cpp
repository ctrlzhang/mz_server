#include "../include/mz_log.h"
#include "../include/mz_singleton.h"
using namespace Meizhi;

class Test
{
    public:
        int a;
};

int main()
{
    Test *t = new Test;
    /*
    typedef MZSingleTon<MZLog> SinMZLog; 
    SinMZLog::GetInstance();
    */
    return 0;
}
