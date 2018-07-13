#include <iostream>
#include <mutex>
#include <thread>
#include <mutex>

using namespace std;
const int SIZE = 10;

mutex myMutex, myMutex1, myMutex2;

void shared_cout_thread_even(int i)
{
    cout << "shared_cout_thread_even" << endl;
    lock_guard<mutex> g1(myMutex1);
    lock_guard<mutex> g2(myMutex2);
    cout << " " << i << " ";
}

void shared_cout_thread_odd(int i)
{
    cout << "shared_cout_thread_odd" << endl;
    lock_guard<mutex> g2(myMutex2);
    lock_guard<mutex> g1(myMutex1);
    cout << " " << i << " ";
}

void shared_cout_main(int i)
{
    lock_guard<mutex> g(myMutex);
    cout << " " << i << " ";
}

void foo(int n)
{
    for(int i = SIZE*(n-1); i < SIZE*n ; i++) {
        if(n % 2 == 0)
            shared_cout_thread_even(i);
        else
            shared_cout_thread_odd(i);
    }
}

int main()
{
    thread t1(foo, 1);  // 0-9
    thread t2(foo, 2);  // 10-19
    thread t3(foo, 3);  // 20-29
    thread t4(foo, 4);  // 30-39
    thread t5(foo, 5);  // 40-49

    for(int i = 0; i > -SIZE; i--)
        shared_cout_main(i);  // (0, -49)

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    return 0;
}