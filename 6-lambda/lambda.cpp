#include <iostream>
#include <thread>

// g++ 6-lambda/lambda.cpp -o obj -std=c++11 -pthread && ./obj
int main()
{
	// lambda is anonymous function
    std::thread t([]()
    {
    	// this is thread body
        std::cout << "thread function\n";
    }
    );
    std::cout << "main thread\n";
    t.join();     // main thread waits for t to finish
    return 0;
}