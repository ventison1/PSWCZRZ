#include <stdio.h>
#include <limits.h>


int main(void)
{
	int pid;
	int flaga=0;
	long pierwsza,i,j;
	
	for(i=1000000000; ;i++)
	{
		for(j=2; j<(i/2); j++)
		{
			if(i%j == 0)
			{
				flaga=1;
			}
		}
		if(flaga!=1)
		{
			printf("\r\n%ld ", i);
		}
		flaga=0;
	}
	return 0;
}
