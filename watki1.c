#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdarg.h>
#include <unistd.h>
#include <signal.h>

#define START_NR 1000000000L

int czy_pierwsza(long n) //zwraca 1, gdy liczba jest liczbą pierwszą
{
	long i;
	for(i=2;i<n/2;i++)
		if(n%i==0)
			return 0;
	return 1;
}

void *liczby_pierwsze(void *arg)
{
	long n; // kolejne liczby
	
	printf("generacja liczb od %ld do %ld\n", START_NR, LONG_MAX);
	for(n=START_NR; n<LONG_MAX; n++)
	{
	if( czy_pierwsza(n) )
		printf(" %ld \n", n);
	}
	return 0;
}

void *get_kod(void *arg)
{
	int kod;
	
	for( ; ; )
	{
		scanf("%d", &kod);
		if( kod == 11)
		{	
			printf("\rZakonczenie programu\n");
			break;
		} else
		  {
			printf("\rZLY KOD \n");
		  }	
	}
return 0;
}

int main(void)
{	
	pthread_t tid,tid2;

	int pid;
	
	pid = fork();	
	
	if(pid == 0)
	{
		execvp( "x-terminal-emulator" , NULL);
	}	
	else if( pid > 0)
	{
		if(pthread_create(&tid, NULL, liczby_pierwsze, NULL))
		{
			printf( "\rBłąd przy tworzeniu wątku 1.\n" );
			abort();
		}
		if(pthread_create(&tid2, NULL, get_kod, NULL))
		{
			printf( "\rBłąd przy tworzeniu wątku 2.\n" );
			abort();
		}
	
	//sleep(1);
	
	pthread_join(tid2, NULL);
	pthread_cancel(tid);
	kill(pid, SIGKILL);
	}
	exit(0);
}
