#include <iostream>
#include <transferQueue.h>
#include <ThreadA.h>
#include <ThreadB.h>
#include <MainThread.h>

int main()
{
    
    MainThread main1(8000);
    main1.ProcRun();
    main1.stop();
    return 0;
}