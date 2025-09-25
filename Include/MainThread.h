#pragma once
#include <thread>
#include <Server.h>
#include <WorkerThread.h>
class MainThread : public Server
{
    public: 
        MainThread(int port):Server(port)
        {
            init();   
            wk.ProcRun();
        }

        ~MainThread()
        {
            
        }

        void ProcRun()
        {
            std::thread t(&MainThread::run , this);
            t1 = std::move(t);
            //t.detach();

        }

        void stop()
        {
            wk.stop();
            t1.join();
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
        WorkerThread wk;
};