#include <iostream>
#include <thread>
#include <list>
#include <algorithm>

using namespace std;

// a global variable
std::list<int> myList;

void addToList(int max, int interval)
{
	for (int i = 0; i < max; i++) {
		if( (i % interval) == 0) myList.push_back(i);
	}
}

void printList()
{
	for (auto itr = myList.begin(), end_itr = myList.end(); itr != end_itr; ++itr ) {
		cout << *itr << ",";
	}
}

// g++ 7-sharing-memory/memory2.cpp -o obj -std=c++11 -pthread && ./obj
int main()
{
	int max = 100;

	// this cause lost of data
	std::thread t1(addToList, max, 1);
	std::thread t2(addToList, max, 10);
	t1.join();
	t2.join();
	std::thread t3(printList);
	t3.join();

	return 0;
}