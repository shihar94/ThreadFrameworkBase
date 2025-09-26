#pragma once 
#include <vector>
#include <iostream>
#include <condition_variable>
#include <thread>
class TransferQueue
{
    public:
        TransferQueue()
        {
            std::cout << "Initialized Transfer Queue " << std::endl;
        }

        ~TransferQueue()
        {

        }

        void insert(int item) 
        {
            {
            std::lock_guard<std::mutex> lock(mtx);
            vec1.push_back(item);
            }
            cv.notify_one();   // wake up the worker thread
        }

        virtual void atInsert(int n){}

        void run()
        {
            while (running) 
            {
                int item;
                {
                    std::unique_lock<std::mutex> lock(mtx);
                    cv.wait(lock, [&]{ return !vec1.empty() || !running; });
                    if (!running) break;
                    item = vec1.front();
                    vec1.pop_back();
                }
                atInsert(item);   // 🔑 executed in *this worker's thread*
            }
        }

        void start() 
        {
            running = true;
            t = std::thread(&TransferQueue::run, this);
        }

        void stop() 
        {
            running = false;
            cv.notify_all();
            if (t.joinable()) t.join();
        }

    public:
        std::vector<int> vec1;
        std::mutex mtx;
        std::condition_variable cv;
        std::thread t;
        bool running = false;
};