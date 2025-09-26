#pragma once 

#include <WorkerThread.h>
#include <transferQueue.h>

class ThreadB : public WorkerThread
{

    public:
        ThreadB()
        {

        }

        void atInsert() override
        {
            std::cout << "Received By B" << std::endl;
            //peer->insert(11);
        }

        void setPeer(MainThread* p)
        {
            peer = p;
            peer->insert(11);
        }

    public:
        MainThread* peer;
    

};