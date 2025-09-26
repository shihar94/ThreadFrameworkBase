#pragma once
#include <thread>
#include <Server.h>
#include <WorkerThread.h>

class MainThread : public Server , public TransferQueue
{
    public: 
        MainThread(int port):Server(port)
        {
            init();   
            
        }

        ~MainThread()
        {
            
        }
        void run1(int n)
        {
            
            if(vec1.size() >= 1)
            {
                //atInsert(n);
            }
            n++;


        }
        void ProcRun() 
        {
            
            //t.detach();

        }

        void stop()
        {
           
            
        }
        void onMessage(int socket)
        {
            
            char buffer[1024] = {0};
            int valread = read(socket, buffer, 1024);
            if (valread > 0) 
            {
                std::cout << "Received: " << buffer << std::endl;
            
            }
        }
        
    public:
        std::thread t1;
        
};