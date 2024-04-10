#include <iostream>

#include <thread>

#include "thread_joinablity.h"
#include "joinAndDetachofThread.h"

void test()
{
    std::cout<<"hello from test\n";
}

void funcA()
{
    std::cout<<"hello from funcA\n";
}

void funcB()
{
    std::cout<<"hello from funcB\n";
    std::thread threadC(test);
    threadC.join();
}

int main()
{
    joinAndDetach();

    
    // std::thread threadA(funcA);

    // std::thread threadB(funcB);
    // threadA.join();

    // std::cout<<"hello from main\n";
    // threadB.join();

    // //discuss about joinablity of a thread
    // threadJoinablity();
    
    

    return 0;

}