#include <iostream>
#include <thread>

class MyFunctor
{
public:
    void operator()() {
        std::cout << "functor\n";
    }
};

// g++ callable_obj.cpp -o o -std=c++11 -pthread && ./o
int main()
{
    MyFunctor functor;
    std::thread t(functor);
    std::cout << "main thread\n";
    t.join();
    return 0;
}