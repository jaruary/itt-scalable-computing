#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS	10

//int arraySize = 50;
long array[50];
long arraySize, start, stop, tid;

void *PrintHello(void *threadid);

void *PrintHello(void *threadid)
{
		arraySize = sizeof(array) / sizeof(array[0]);

		//long chunk = arraySize / NUM_THREADS;
		long chunk = arraySize / NUM_THREADS;		//	This gets the size of the array by dividing it's total size by each array element size, and then dividing that by the number of threads...
		//printf("\nChunk = %ld", chunk);
		
		tid = (long)threadid;
		//printf("\nTid = %d", (int)threadid);

		start = chunk * tid;
		//printf("\nStart = %d", start);

		stop = start + chunk;
		//printf("\nStop = %d", stop);

		for(int i = start; i < stop; i++)
			{
				array[i] = (long)tid;	
			}							
}


int main (int argc, char *argv[])
{
   

    pthread_t threads[NUM_THREADS];

   	arraySize = sizeof(array) / sizeof(long);	//	define the size of the array here, so it can be used for the 2nd FOR loop

   //	1st FOR loop
   for(long t = 0; t < NUM_THREADS; t++)
    {
      int rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
    }

   //	2nd FOR loop
   for(int i = 0; i < arraySize; i++)
	{
				//	The output of this will vary for each execution, due to not using any pThread barrier...
				printf("\nThread id_%ld at index_%d", array[i], i);
	}	

	printf("\n");

   pthread_exit(NULL);

}