#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

int
main(void)
{
	double n;      /*the amount of data used by the subscriber*/

	printf("Enter the amount of the data used by the subscriber (the data must beyond 0) =>");   /*print message to indicate bad data as well*/
    scanf("%lf", &n);


	/*give conditions and output the result of the charges to be paid by the subscriber*/
	if (n > 0.0 && n <= 1.0)
	{
		printf("The charges to be paid by the subscriber are 250.\n");
	}
	else if (n > 1.0 && n <= 2.0)
	{
		printf("The charges to be paid by the subscriber are 500.\n");
	}
	else if (n > 2.0 && n <= 5.0)
	{
		printf("The charges to be paid by the subscriber are 1000.\n");
	}
	else if (n > 5.0 && n <= 10.0)
	{
		printf("The charges to be paid by the subscriber are 1500.\n");
	}
	else if (n > 10.0)
	{
		printf("The charges to be paid by the subscriber are 2000.\n");
	}



	system("PAUSE");
	return(0);
}