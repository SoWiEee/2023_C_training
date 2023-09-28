/* Observe boiling point of a substance */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cstdlib>

int within_x_percent(int, double, double);  /* Calculate the range of the boiling point of the substance */

int main()
{
    int ref;            /* the refence of substance from the question */
	double x = 0.05;    /* the percentage value from the question */
    double data;        /* input - the data of the temperature of the substance */
    
	/* Read the temperature of the substance */
    printf("Enter the temperature of the substance> ");
    scanf("%lf", &data);
	
	/* Identify the substance */
	if (within_x_percent(100, data, x))
	{
		printf("This substance is Water.\n");
	}
	else if (within_x_percent(357, data, x))
	{
		printf("This substance is Mercury.\n");
	}
	else if (within_x_percent(1187, data, x))
	{
		printf("This substance is Copper.\n");
	}
	else if (within_x_percent(2193, data, x))
	{
		printf("This substance is Silver.\n");
	}
	else if (within_x_percent(2660, data, x))
	{
		printf("This substance is Gold.\n");
	}
	else
	{
		printf("Substance unknown.");
	}

    system("PAUSE");
	return 0;
}

int within_x_percent(int ref, double data, double x)
{
    if((ref - ref * x) <= data <= (ref + ref * x))
        return 1;
    else 
        return 0;
}
