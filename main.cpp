#include <iostream>
#include <transferQueue.h>
#include <ThreadA.h>
#include <ThreadB.h>
#include <MainThread.h>

int main()
{
    ThreadB* mainB = new ThreadB();
    ThreadA* mainA = new ThreadA(8000 , mainB);
    

    // start threads
    mainB->start();
    mainA->start();
mainB->setPeer(mainA);
    // send messages
    mainA->sendToWorker(42);
    
    //mainB->peer->insert(99);

    // wait a bit
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // stop threads
    mainB->stop();
    mainA->stop();
    
    //mainA->stop();
    return 0;
}