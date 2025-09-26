#pragma once


#include <MainThread.h>
#include <transferQueue.h>


class ThreadA : public MainThread 
{
    public:
        ThreadA(int port , WorkerThread* wk):MainThread(port)
        {   
            m_wk = wk;
            

        }
        
        void atInsert(int item) override 
        {
            std::cout << "ThreadA [" << std::this_thread::get_id() << "] received: " << item << std::endl;
            sendToWorker(++item);
        }
        

        void sendToWorker(int value) 
        {
            if (m_wk) m_wk->insert(value);
        }
    public:
        WorkerThread* m_wk;
        

};