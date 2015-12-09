/**
 * @file mz_singleton.h
 * @Brief singleton 
 * @author ctrlzhang
 * @version v1
 * @date 2015-12-07
 */
#ifndef _MZ_SINGLETON_H_
#define _MZ_SINGLETON_H_

#include <stdlib.h>

namespace Meizhi
{
    template<typename T>
    class MZSingleTon
    {
        public:
            static T* GetInstance()
            {
                if(NULL == _pInstance)
                {
                    _pInstance = new T;
                    atexit(&DestroyInstance);
                }

                return _pInstance;
            }

        private:
            MZSingleTon() {}
            ~MZSingleTon() {}
            
            static void DestroyInstance()
            {
                if(_pInstance)
                {
                    delete _pInstance;
                    _pInstance = NULL;
                }
            }

        private:
            static T* _pInstance;
    };

    template<typename T>
    T* MZSingleTon<T>::_pInstance = NULL;
}

#endif
