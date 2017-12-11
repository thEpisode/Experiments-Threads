#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *worker(void* arg);

int main(int argc, char **argv)
{
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

	exit(0);
}

void *worker(void* arg)
{

	pthread_mutex_lock(&mutex);

	// Do something

	pthread_mutex_unlock(&mutex);

	return 0;
}