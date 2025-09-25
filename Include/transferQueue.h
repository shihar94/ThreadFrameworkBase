#pragma once 
#include <vector>
#include <iostream>

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
        void insert(int n)
        {
            std::cout << "Inserted item: " << n << std::endl;
            vec1.push_back(n);
            atInsert();
        }
        virtual void atInsert()
        {

        }

    public:
        std::vector<int> vec1;
};