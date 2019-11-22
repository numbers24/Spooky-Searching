#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "multitest.h"

int foundindex; //global variable that will be set to the index pointing to the key location once one of the threads finds the key

int current = -1; //current thread counter that will increase by one for each thread, determining the segment each thread will search (resets to -1 before return)

//argument struct to be passed into the void* parameter in pthread_create
typedef struct arguments{
	int key;
	int max;
	int threadnum;
}argarr;

//linear search algorithm that each thread runs through
void *searchThread (void* args){
	argarr *input = (argarr*)args;
	int key = input->key;
	int max = input->max;
	int threadnum = input->threadnum;
	int curr = ++current;
	int i;
	for (i = (curr * (max/threadnum)); i < ((curr+1) * (max/threadnum)); i++){
		if (key == arr[i]){
			foundindex = i;
		}
	}
}

//function to calculate amount of threads necessary for function, create threads to search array, join threads, and return the index result
int search (int key, int max){
	int threadnum = 0;
	int i;
	for (i = 1; i < 1000; i++){
		if ((max/i) <= 250){
			threadnum = i;
			break;
		}
	}
	pthread_t thread[threadnum];
	argarr *args = (argarr*)malloc(sizeof(argarr));
	args->key = key;
	args->max = max;
	args->threadnum = threadnum;
	int j;
	for (j = 0; j < threadnum; j++){
		pthread_create(&thread[j], NULL, searchThread, (void*)args);
	}
	int k;
	for (k = 0; k < threadnum; k++){
		pthread_join(thread[k], NULL);
	}
	free(args);
	current = -1;
	return foundindex;
}

//function returning the search type used (0 = Process, 1 = Thread)
int type(){
	return 1;
}
