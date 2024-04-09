#include <iostream>

#include <thread>

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
    std::thread threadA(funcA);

    std::thread threadB(funcB);
    threadA.join();

    std::cout<<"hello from main\n";
    threadB.join();
    
    

    return 0;

}