#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "multitest.h"

int foundindex;

int current = -1;

typedef struct arguments{
	int key;
	int max;
	int threadnum;
}argarr;

void *searchThread (void* args){
	argarr *input = (argarr*)args;
	int key = input->key;
	int max = input->max;
	int threadnum = input->threadnum;
	int curr = ++current;
	//int *arr = input->arr;
	int i;
	for (i = (curr * (max/threadnum)); i < ((curr+1) * (max/threadnum)); i++){
		if (key == arr[i]){
			foundindex = i;
		}
	}
}

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
	printf("key: %d, max: %d, threadnum: %d\n", key, max, threadnum);
	/*int l;
	for (l = 0; l < max; l++){
		args->arr[l] = arr[l];
	}*/
	int j;
	for (j = 0; j < threadnum; j++){
		pthread_create(&thread[j], NULL, searchThread, (void*)args);
	}
	int k;
	for (k = 0; k < threadnum; k++){
		pthread_join(thread[k], NULL);
	}
	printf("index: %d\n", foundindex);
	return foundindex;
}
