#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int foundindex;

typedef struct arguments{
	int key;
	int max;
	int threadnum;
	int curr;
	int arr[];
}argarr;

void *searchThread (void* args){
	argarr *input = (argarr*)args;
	int key = input->key;
	int max = input->max;
	int threadnum = input->threadnum;
	int curr = input->curr;
	int *arr = input->arr;
	int i;
	for (i = (curr * (max/threadnum)); i < ((curr+1) * (max/threadnum)); i++){
		if (key == arr[i]){
			foundindex = i;
		}
	}
}

int search (int key, int max, int arr[]){
	int threadnum = 0;
	int i;
	for (i = 1; i < 1000; i++){
		if ((max/i) <= 250){
			threadnum = i;
			break;
		}
	}
	pthread_t thread[threadnum];
	argarr *args = (argarr*)malloc(sizeof(argarr) + max*sizeof(int));
	args->key = key;
	args->max = max;
	args->threadnum = threadnum;
	int l;
	for (l = 0; l < max; l++){
		args->arr[l] = arr[l];
	}
	int j;
	for (j = 0; i < threadnum; i++){
		args->curr = i;
		pthread_create(&thread[i], NULL, searchThread, (void*)args);
	}
	int k;
	for (k = 0; i < threadnum; i++){
		pthread_join(thread[i], NULL);
	}
	return foundindex;
}

int main(){
	return 0;
}
