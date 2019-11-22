#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
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

void workload (int iter){
	int key = rand() % MAX;
	printf("     Iteration: %d\n     Parameters: (key = %d, max = %d)\n", iter, key, MAX);
	int i;
	int index1;
	int index2;
	int temp;
	for (i = 0; i < 150; i++){
		index1 = test(key, MAX);
		index2 = rand() % MAX;
		temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
		printf("          Workload Iteration: %d, Key at Index: %d\n", i, index1);
	}
	return;
}

int main(){
	srand(time(NULL));
	clock_t start, end;
	double times[100];
	double total = 0.0;
	double total1 = 0.0;
	double min, max;
	double avg = 0.0;
	double var;
	double stddev;
	int i;
	int testnum;
	int searchtype = type();
	if (searchtype == 0){
		printf("Search Type: Process\n");
	}else{
		printf("Search Type: Thread\n");
	}
	initialize();	
	testnum = 1;
	printf("Test Number: %d\n", testnum);
	for (i = 0; i < 100; i++){
		start = clock();
		workload(i);
		end = clock();
		times[i] = (((double) (end - start)) / CLOCKS_PER_SEC) * 1000;
		total += times[i];
	}
	avg = total/100;
	min = times[0];
	max = times[0];
	for (i = 0; i < 100; i++){
		total1 += pow((times[i] - avg), 2);
		if (times[i] < min){
			min = times[i];
		}
		if (times[i] > max){
			max = times[i];
		}
	}
	var = total1/100;
	stddev = sqrt(var);
	printf("Minimum: %f milliseconds\nMaximum: %f milliseconds\nAverage: %f milliseconds\nStandard Deviation: %f milliseconds\n", min, max, avg, stddev);	
	return 0;
}
