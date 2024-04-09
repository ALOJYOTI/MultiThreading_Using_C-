
#include <iostream>
#include <thread>


#include "thread_joinablity.h"


/* a properly cronstructed thread object represent an active thread of execution in hardware level. such a thread is joinable

for each joinable thread, we muct call either join or detach function

after we make such a call that thread become non joinable

if u forget to join or detach on a joinable thread, then at the time of destructor call to that thread object, std::terminate function will be called by default

if any program have std::terminate call, we refer that program as unsafe program
*/

/*
joinable() function for thread
joinable function is an inbuilt function and will return boolean if an active thread is joinable

once we join or detah a thread it is no more active thread.

**** check joinablity of a thread before join or detach it.
*/


void threadJoinablity()
{
    std::thread thread1(test1);

    //if we do not join a active thread, error will be thrown like below. 
    /*terminate called without an active exception
    Aborted
    */
    if(thread1.joinable())
    {
        std::cout<<"thread1 is joinable\n";
    }
    else
    {
        std::cout<<"thread1 is not joinable\n";
    }

    thread1.join();

    if(thread1.joinable())
    {
        std::cout<<"thread1 is joinable\n";
    }
    else
    {
        std::cout<<"thread1 is not joinable\n";
    }

    defaultThreadConstruction();
}

void test1()
{
    std::cout<<"Hello from test1\n";
}

/*
what is a properly constructed thread?
-->>if we default constructed a thread then it does not have any active thread of execution , so this is non joinable. 
*/

void defaultThreadConstruction()
{
    std::thread thread2;
    //this thread 2 object is initialied with default constructor of std::thread class. so it is not an active thread.

    if(thread2.joinable())
    {
        std::cout<<"thread2 is joinable\n";
    }
    else
    {
        std::cout<<"thread2 is not joinable\n";
    }

}


