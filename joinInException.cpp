/*
if there are other operation in between launch and join of a thread, and that other operation throws any exception,
then the join operation will skip. that will abort the program. 

solution:

RAII -> resources acquisition is initialization (constructor will acquire resources and destructor will release resources) same as object

we will create a new clas call thread_guard. which will be reused for handling thread object
*/

#include <iostream>

#include "threadGuard.h"

void foo()
{
    std::cout<<"This is foo\n";
}
void other_operation()
{
    std::cout<<"this is other operation\n";
    throw std::runtime_error("this is runtime error");
}

void run()
{
    std::thread foo_thread(foo);
    ThreadGuard tg(foo_thread);

    try
    {
        other_operation();
    }
    catch(...)
    {
        std::cout<<"foo_thread has been joined\n";
    }
}

