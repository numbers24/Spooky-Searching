#include <stdlib.h>

#ifndef _MULTITEST_H  //guard function start
#define _MULTITEST_H

#define test(x, y) search(x, y) //replace test call with proc or thread search (depends on make)

#define MAX 1000

int arr[MAX];

int search (int key, int max);

#endif