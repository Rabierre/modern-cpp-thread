#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <mutex>

using namespace std;

mutex myMutex;

// g++ 8/fork_and_join.cpp -o obj -std=c++11 -pthread && ./obj
// http://www.bogotobogo.com/cplusplus/multithreaded4_cplusplus11B.php
int main()
{
    // vector container stores threads
    std::vector<std::thread> workers;

    int resource[] = {1,2,3,4,5,6,7,8,9,10};
    int from = 0, to = 2;
    int minSize = 2;

    for (int i = 0; i < 5; i++) {
        workers.push_back(std::thread([resource, from, to]()
        {
            lock_guard<mutex> g(myMutex);
            cout<<"threadid "<<std::this_thread::get_id()<<": "<<from<<","<<to<<endl;

            for (int i = from; i<to; i++)
            {
                cout<<resource[i]<<endl;
            }
        }));
        from+=minSize;
        to+=minSize;
    }

    // for (int i=0; i<workers.size(); i++)
    std::for_each(workers.begin(), workers.end(), [](std::thread &t)
    {
        t.join();
    });

    return 0;
}