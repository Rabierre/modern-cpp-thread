#include <iostream>
#include <thread>
#include <future>


int simplefunc(std::string a)
{
	std::cout<<"threadid "<<std::this_thread::get_id()<<": "<<a<<std::endl;
	return a.size();
}

// g++ 9/future.cpp -o obj -std=c++11 -pthread && ./obj
int main()
{
	// async
	auto future = std::async(std::launch::async, simplefunc, "hello world");
	int simple = future.get();
	std::cout<<simple<<std::endl;

	// deferred
	// means lazy mode
	std::cout<<"main threadid "<<std::this_thread::get_id()<<": "<<std::endl;
	auto future2 = std::async(std::launch::deferred, simplefunc, "hello world");
	future2.get();

	return 0;
}