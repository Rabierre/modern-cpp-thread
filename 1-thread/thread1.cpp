#include <iostream>
#include <thread>

void thread_function()
{
    std::cout << "thread function\n";
}

// g++ thread1.cpp -o thread1 -std=c++11 -pthread
// -pthread
//        Adds support for multithreading with the pthreads library.  This
//        option sets flags for both the preprocessor and linker.
int main()
{
    std::thread t(&thread_function);   // t starts running
    std::cout << "main thread\n";
    t.join();   // main thread waits for the thread t to finish
    return 0;
}
