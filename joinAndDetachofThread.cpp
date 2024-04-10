#include <iostream>
#include <thread>

   
void foo()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(6000));
    std::cout<<"Hello from foo\n";
}

void bar()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::cout<<"Hello from bar\n";
}

void joinAndDetach()
{
    std::thread foo_thread(foo);
    std::thread bar_thread(bar);

    bar_thread.detach();
    std::cout<<"This is after bar thread detach\n";

    foo_thread.join();
    std::cout<<"This is after foo thread join\n";
}


/*
A C++ thread object generally (but not always) represents a thread of execution, which is an OS or platform concept.

When thread::join() is called, the calling thread will block until the thread of execution has completed. 
Basically, this is one mechanism that can be used to know when a thread has finished. 
When thread::join() returns, the OS thread of execution has completed and the C++ thread object can be destroyed.

When the thread::detach() is called, the thread of execution is "detached" from the thread object and is no longer represented by a thread object
 - they are two independent things. The C++ thread object can be destroyed and the OS thread of execution can continue on. 
 If the program needs to know when that thread of execution has completed, some other mechanism needs to be used. join() cannot be called on that thread object any more, 
 since it is no longer associated with a thread of execution.

It is considered an error to destroy a C++ thread object while it is still "joinable". 
That is, in order to destroy a C++ thread object either join() needs to be called (and completed) or detach() must be called. 
If a C++ thread object is still joinable when it's destroyed, an exception will be thrown.

Some other ways that a C++ thread object will not represent a thread of execution (ie., can be unjoinable):
	• A default constructed thread object does not represent a thread of execution, so is not joinable.
	• A thread that has been moved from will no longer represent a thread of execution, so is not joinable.

*/