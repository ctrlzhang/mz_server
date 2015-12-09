#ifndef _EVENT_LOOP_H_
#define _EVENT_LOOP_H_

#include <event2/listener.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>

#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

namespace Meizhi
{
    class MZEventloop
    {
        private:
            struct event_base* _pBase;
    };
}

#endif
