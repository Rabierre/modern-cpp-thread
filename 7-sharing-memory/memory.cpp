#include <iostream>
#include <thread>
#include <string>
#include <mutex>

std::mutex mu;

void shared_cout(std::string msg, int id)
{
	mu.lock();
	//  two threads get the cout resource in a ramdom fashion
	std::cout << msg << ":" << id << std::endl;
	mu.unlock();
}
void thread_function()
{
	for (int i = -10; i < 0; i++)
		shared_cout("thread function", i);
}

// g++ 7-sharing-memory/memory.cpp -o obj -std=c++11 -pthread && ./obj
int main()
{
	std::thread t(&thread_function);
	for (int i = 10; i > 0; i--)
	    shared_cout("main thread", i);
	t.join();
	return 0;
}