#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>      /*printf, scanf definitions*/
#include<stdlib.h>      /*system definition*/

int
main(void)
{
	double Volume,      /*the volume to be infused*/
		   Minutes,     /*minutes over which to infuse*/
		   Rate;        /*how much to take per hour*/

	printf("Volume to be infused (ml) => ");
	scanf("%lf", &Volume);                                /*enter the volume to be infused*/
	printf("Minutes over which to infuse =>");
	scanf("%lf", &Minutes);                               /*enter minutes over which to infuse*/

	Rate = 60 / Minutes * Volume;                         /*compute the rate*/

	printf("VTBI: %g ml\n", Volume);
	printf("Rate: %g ml/hr", Rate);

	system("PAUSE");
	return(0);
}