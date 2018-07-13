#include <iostream>
#include <thread>

void thread_function()
{
    std::cout << "thread function\n";
}

// g++ 4/thread7.cpp -o obj -std=c++11 -pthread && ./obj
int main()
{
    std::thread t(&thread_function);
    std::cout << "main thread\n";
    // error
    std::thread t2 = t;

    t2.join();

    return 0;
}