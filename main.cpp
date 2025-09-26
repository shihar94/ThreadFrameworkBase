#include <iostream>
#include <transferQueue.h>
#include <ThreadA.h>
#include <ThreadB.h>
#include <MainThread.h>

int main()
{
    ThreadB* mainB = new ThreadB();
    ThreadA* mainA = new ThreadA(8000 , mainB);
    mainB->setPeer(mainA);
    mainA->ProcRun();
    mainA->stop();
    return 0;
}