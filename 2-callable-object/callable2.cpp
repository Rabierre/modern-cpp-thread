#include <iostream>
#include <thread>

class MyFunctor
{
public:
    void operator()() {
        std::cout << "functor\n";
    }
};

// g++ callable2.cpp -o o -std=c++11 -pthread && ./o
int main()
{
    std::thread t(MyFunctor());   // this won't work
    // std::thread t((MyFunctor())); // this works
    std::cout << "main thread\n";
    t.join();
    return 0;
}