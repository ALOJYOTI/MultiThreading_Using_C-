/*
we can call detach function as soon as we launch a thread. as detach will not block the calling thread

in some occation, we can not call join function as soon as we launch a thread, as join call block a calling thread.

command to execute this case -> g++ main.cpp joinInException.cpp threadGuard.h -std=c++0x -pthread -o main.out
*/

void run();