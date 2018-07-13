#include <iostream>
#include <thread>
#include <string>

void thread_function(std::string param)
{
    std::cout << "thread function ";
    std::cout << "message is = " << param << std::endl;
}

void thread_function2(std::string &s)
{
    std::cout << "thread function2 ";
    std::cout << "message is = " << s << std::endl;
    s = "Justin Beaver";
}

// g++ thread6.cpp -o obj -std=c++11 -pthread && ./obj
int main()
{
    std::string name = "Kathy Perry";
    // copy by value
    std::thread t(&thread_function, name);
    // reference
    std::thread t2(&thread_function2, std::ref(name));
    // memory
    // std::thread t3(&thread_function2, std::move(name));
    std::cout << "main thread message = " << name << std::endl;
    t.join();
    t2.join();
    // t3.join();
    return 0;
}