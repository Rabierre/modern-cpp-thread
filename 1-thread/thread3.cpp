#include <iostream>
#include <thread>

void thread_function()
{
    std::cout << "thread function\n";
}

// g++ thread3.cpp -o thread3 -std=c++11 -pthread && ./thread3
int main()
{
    std::thread t(&thread_function);
    std::cout << "main thread\n";
    if (t.joinable())
    {
        t.join();
    }
    return 0;
}