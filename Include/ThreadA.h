#pragma once


#include <MainThread.h>
#include <transferQueue.h>


class ThreadA : public MainThread 
{
    public:
        ThreadA(int port , WorkerThread* wk):MainThread(port)
        {   
            m_wk = wk;
            m_wk->insert(10);

        }
        
        void atInsert() override
        {
            std::cout << "Received By A" << std::endl;
            
        }
    public:
        WorkerThread* m_wk;
        

};