#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "multitest.h"

int search(int key, int max)
{	int i,j,k,val,temp;
	pid_t pid;
	if(max%250)
	j=max/250+1;
	else
	j=max/250;
	
	pid_t pidr[j];

	for(i=0;i<j;i++)
	{	
		pid=fork();
		if(pid)
		pidr[i]=pid;
		else
		{
			for(k=i*250;k<((i+1)*250)&&k<max;k++)
			{		
				if(arr[k]==key)
				{
					if(k%250==0)
					exit(251);						
					exit(k%250);
				}
			}
			exit(0);
		}
	}
	for(i=0;i<j;i++)
	{
		waitpid(pidr[i],&val,0);
			if(val)
			{
				if(val==251*256)
				val=i*250;
				else
				val=WEXITSTATUS(val)+(i*250);
				//printf("Found key %d at index %d\n",arr[val],val);
				temp=val;			
			}	
	}	
	//printf("\n");
	return temp;
}

int type(){
	return 0;
}
