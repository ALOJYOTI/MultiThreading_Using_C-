#include <thread>


class ThreadGuard
{
    std::thread& t; // class attribute. ref to a thread object

public:
// constructor -> takes a thread object _t as a ref and pass that object to local thread object t
    explicit ThreadGuard(std::thread& _t) : t(_t)
    {}

//destructor
    ~ThreadGuard()
    {
        if(t.joinable())
        {
            t.join();
        }
    }

// we dont want to copy threadguard type object from one to another. so delete the copy constructor and copy assignment operator.
    ThreadGuard(ThreadGuard & ) = delete;
    ThreadGuard & operator= (ThreadGuard & ) = delete;

};