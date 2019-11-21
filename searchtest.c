#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "multitest.h"

void initialize(){
	int i;
	for (i = 0; i < MAX; i++){
		arr[i] = i;
	}
	int pairs = (MAX * 0.75) + 1;
	int j;
	int index1;
	int index2;
	int temp;
	for (j = 0; j < pairs; j++){
		index1 = rand() % MAX;
		index2 = rand() % MAX;
		temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}
	return;
}

void workload(){
	int key = rand() % MAX;
	int i,index1,index2,temp;
	for (i=0; i < 100; i++,index1=index2=temp=0)
	{
		index1 = test(key, MAX);
		index2 = rand() % MAX;
		printf("index1: %d, index2: %d\n", index1, index2);
		printf("val1: %d, val2: %d\n\n", arr[index1], arr[index2]);
		temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}
	return;
}

int main(){
	srand(time(NULL));
	initialize();
	workload();
	return 0;
}
