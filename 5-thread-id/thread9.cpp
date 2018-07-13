#include <iostream>
#include <thread>

void thread_function(std::string param)
{
    std::cout << "thread function\n";
}

// g++ 5-thread-id/thread9.cpp -o obj -std=c++11 -pthread && ./obj
int main()
{
    std::string s = "Kathy Perry";
    std::thread t(&thread_function, s);
    std::cout << "main thread message = " << s << std::endl;

    std::cout << "main thread id = " << std::this_thread::get_id() << std::endl;
    std::cout << "child thread id = " << t.get_id() << std::endl;

    t.join();
    return 0;
}