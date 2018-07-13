#include <iostream>
#include <mutex>
#include <thread>
#include <mutex>

using namespace std;

class MyObjectClass {};

void swap(MyObjectClass& lhs,MyObjectClass& rhs);

class X
{
private:
	MyObjectClass myObj;
	std::mutex m;
public:
	X(MyObjectClass const& obj):myObj(obj){}
	friend void swap(X& lhs, X& rhs)
	{
		// the arguments are checked to ensure they are different instances,
		// because attempting to acquire a lock on a std::mutex
		// when we already hold it is undefined behavior.
		if(&lhs==&rhs) return;

		// the call to std::lock() locks the two mutexes
		std::lock(lhs.m,rhs.m);

		// two std::lock_guard instances are constructed one for each mutex.
		std::lock_guard<std::mutex> lock_a(lhs.m,std::adopt_lock);
		std::lock_guard<std::mutex> lock_b(rhs.m,std::adopt_lock);

		swap(lhs.myObj, rhs.myObj);
	}
};


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