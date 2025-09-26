#pragma once 

#include <WorkerThread.h>
#include <transferQueue.h>

class ThreadB : public WorkerThread
{

    public:
        ThreadB()
        {

        }

        void atInsert(int item) override 
        {
            std::cout << "ThreadB [" << std::this_thread::get_id() << "] received: " << item << std::endl;
            peer->insert(++item);
        }

        void setPeer(MainThread* p)
        {
            peer = p;
            //peer->insert(11);
        }

    public:
        MainThread* peer;
    

};