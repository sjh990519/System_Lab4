/*
 쓰레드 인자 전달
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *hello_thread(void *arg)
{
	printf(" Thread : Hi I'm Thread~! \n");
	return arg;
}


int main()
{

	pthread_t pid[NUM_THREADS];
	int i, status;
	
	// pthread create
	for(i=0; i<NUM_THREADS; i++)
	{
		status = pthread_create(&pid[i], NULL, hello_thread, (void*)i);
		if(status != 0)
		{
			fprintf(stderr, "Create thread %d : %d", i, status);
			exit(1);
		}
	}
	pthread_exit(NULL);
}
