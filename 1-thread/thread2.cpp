#include <iostream>
#include <thread>

void thread_function()
{
    std::cout << "thread function\n";
}

// g++ thread2.cpp -o thread2 -std=c++11 -pthread && ./thread2
int main()
{
    std::thread t(&thread_function);
    std::cout << "main thread\n";
    t.detach();
    t.join();   // Error
    return 0;
}
