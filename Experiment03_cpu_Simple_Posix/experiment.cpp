#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <vector>
#include <random>
#include <ctime>
#include <cstdio>
#include <chrono>
#include <sys/time.h>

#define NUM_THREADS 18

using namespace std;
using namespace std::chrono;

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *worker(void *arg);
int randGen(const int &min, const int &max);

int main(int argc, char **argv)
{
	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	pthread_t threads[NUM_THREADS];
	int thread_args[NUM_THREADS];
	int result_code;

	for (unsigned int i = 0; i < NUM_THREADS; ++i)
	{
		/// Last argument is to pass in worker function
		if ((result_code = pthread_create(&threads[i], NULL, worker, NULL)))
		{
			printf("Thread creation failed: %d\n", result_code);
		}
	}
	for (int i = 0; i < NUM_THREADS; ++i)
	{
		result_code = pthread_join(threads[i], 0);
	}

	high_resolution_clock::time_point t2 = high_resolution_clock::now();
    double dif = duration_cast<nanoseconds>(t2 - t1).count();
    printf("Elasped time is %lf seconds.\n", (dif/1000000000));

	exit(0);
}

void *worker(void *arg)
{
	int i = 0;
	while (true)
	{
		if (i < 14000000 / NUM_THREADS)
		{
			int rval = randGen(10, 50);
		}
		else
		{
			break;
		}
		i++;
	}
	/* pthread_mutex_lock(&mutex);

	// Do something

	pthread_mutex_unlock(&mutex); */

	return 0;
}

int randGen(const int &min, const int &max)
{
	static thread_local mt19937 generator(0);
	uniform_int_distribution<int> distribution(min, max);
	return distribution(generator);
}