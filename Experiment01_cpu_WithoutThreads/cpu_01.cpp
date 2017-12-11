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

int randGen(const int &min, const int &max)
{
	std::random_device device;
	static thread_local mt19937 generator(device());
	//printf("%d|", device());
	uniform_int_distribution<int> distribution(min, max);
	return distribution(generator);
}

int main()
{
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	int i = 0;
	while (true)
	{
		if (i < 14000000)
		{
			int rval = randGen(10, 50);
		}
		else
		{
			break;
		}
		i++;
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	double dif = duration_cast<nanoseconds>(t2 - t1).count();
	printf("Elasped time is %lf seconds.\n", (dif / 1000000000));
	return 1;
}