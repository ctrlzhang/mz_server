#ifndef _MZ_FILE_H_
#define _MZ_FILE_H_

#include "mz_common.h"
#include <fstream>

namespace Meizhi
{
    class MZFile
    {
        public:
            MZFile(const char* filename, OpenMode mode)
            {
                switch(mode)
                {
                    case OPEN_MODE_R:
                        open(filename, fstream::in);
                        break;
                    case OPEN_MODE_W:
                        open(filename, fstream::out);
                        break;
                    case OPEN_MODE_RW:
                        open(filename, fstream::in | fstream::out);
                        break;
                    case OPEN_MODE_APP:
                        open(filename, fstream::in | fstream::out | fstream::app);
                        break;
                    default:
                        open(filename, fstream::in | fstream::out);
                }
            }

            void open(const char* filename, ios_base::openmode mode)
            {
                _fs.open(filename, mode);
            }

            void close()
            {
                _fs.close();
            }

            void read(char* buff, int32_t n)
            {
                _fs.read(buff, n);
            }

            void write(const char* buff, int32_t n)
            {
                _fs.write(buff, n);
            }

        private:
            fstream _fs; 
    };
}
#endif
