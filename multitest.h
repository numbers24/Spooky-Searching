#include <stdlib.h>

#ifndef _MULTITEST_H  //guard function start
#define _MULTITEST_H

#define test(x, y, z) search(x, y, z) //replace test call with proc or thread search (depends on make)

void *searchThread (void* args);
int search (int key, int max, int arr[]);

#endif