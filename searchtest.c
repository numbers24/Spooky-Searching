#include <stdlib.h>
#include <stdio.h>
#include "multitest.h"
#define MAX 1001

int testarr[MAX];

void initialize(){
	for (int i = 0; i < MAX; i++){
		testarr[i] = i;
	}
	int pairs = (MAX * 0.75) + 1;
	for (int i = 0; i < pairs; i++){
		int index1 = rand() % MAX;
		int index2 = rand() % MAX;
		while (index2 == index1){
			index2 = rand() % MAX;
		}
		int temp = testarr[index1];
		testarr[index1] = testarr[index2];
		testarr[index2] = temp;
	}
	return;
}
void workflow()
{
	int i,j;
	for(j=0;j<MAX;j++)
	{
		for(i=1;i<MAX;i++)
		test(j%i,MAX,testarr);
	}
}
int main(){
	initialize();
	workflow();
	return 0;
}
