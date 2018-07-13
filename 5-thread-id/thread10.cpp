#include <iostream>
#include <thread>

void thread_function()
{
    std::cout << "thread function\n";
}

// g++ 5-thread-id/thread10.cpp -o obj -std=c++11 -pthread && ./obj
int main()
{
	// suggestion for the number of threads
    std::cout << "Number of threads = "
              <<  std::thread::hardware_concurrency() << std::endl;
	// std::thread t(&thread_function);
	// t.join();
    return 0;
}