#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <random>

#include <ctime>
#include <cstdio>
#include <chrono>
#include <sys/time.h>

using namespace std;
using namespace std::chrono;

#define NUM_THREADS     18

mutex cout_mtx;

int randGen(const int& min, const int& max) {
    static thread_local mt19937 generator(hash<thread::id>()(this_thread::get_id()));
    uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

void threadFnc(int tid)
{
    int i = 0;
    while (true)
    {
        if (i < 1000000000 / NUM_THREADS)
        {
            int rval = randGen(10, 50);
        }
        else
        {
            break;
        }
        i++;
    }
}

int main()
{
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    thread threads[NUM_THREADS];

    for (unsigned int i = 0; i < NUM_THREADS; ++i){
        threads[i] = thread(threadFnc, i);
    }

    for (auto& th : threads){
        th.join();
    }
    
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    double dif = duration_cast<nanoseconds>(t2 - t1).count();
    printf("Elasped time is %lf seconds.\n", (dif/1000000000));

    return 1;
}
