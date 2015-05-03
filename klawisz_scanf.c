#include <stdio.h>
#include <limits.h>


int main(void)
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
