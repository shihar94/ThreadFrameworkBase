#pragma once 
#include <transferQueue.h>
#include <thread>
#include <Main.h>

class WorkerThread : public Main, public TransferQueue
{   
    public:
        WorkerThread()
        {
            
        }
        
        ~WorkerThread()
        {
            
        }

        void ProcRun()
        {
            //std::thread t1(&WorkerThread::run , this);
            //t = std::move(t1);
        }

        void stop()
        {
            //t.join();
        }

        public:
            std::thread t;

};