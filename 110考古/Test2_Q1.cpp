/*
 * Separate a number into three parts: a sign (+, - or blank), a whole number magnitude, and a fractional part.
 */
 
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void separate(double num, char *signp, int *wholep, double *fracp);

int main()
{
	FILE *inp;	        /* pointer to input file						*/
	double value;		/* input - number to analyze					*/
	char sn;			/* output - sign of value						*/
	int whl;			/* output - whole number magnitude of value		*/
	double fr;			/* output - fracrional part of value			*/
	int input_status;	/* status value returned by fscanf				*/
	char discard;		/* unprocessed character from input file		*/

	/* Prepare file for input */
	inp = fopen("number.txt", "r");

	/* Check input file exist */
	if (inp == NULL)
	{
		printf("Input file no exist.\n");
		system("PAUSE");
		exit(1);
	}

	/* Input each item and print results */
	do
	{
		/* Input an item from input file */
		input_status = fscanf(inp, "%lf", &value);

		/* Handle the invalid input, or separate input value */
		if (input_status == 0)
		{
			printf("Invalid input\n");
			
			/* Discard invalid input */
			do
			{
				fscanf(inp, "%c", &discard);
			} while (discard != '\n');
		}
		else if (input_status == 1)
		{
			/* Separate input value and print result */
			separate(value, &sn, &whl, &fr);
			printf("Parts of %.2f\n\n sign: %c\n", value, sn);
			printf(" whole number magnitude: %d\n", whl);
			printf(" fractional part: %.2f\n", fr);
		}
			
	} while (input_status != EOF);

	
	/* close file */
	fclose(inp);

	system("PAUSE");
	return 0;
}

/*
 * Separate a number into three parts: a sign (+, - or blank),
 * a whole number magnitude, and a fractional part
 */
void 
separate(double  num,		/* input - value to be split				*/
		 char   *signp,		/* output - sign of num						*/
		 int    *wholep,	/* output - whole number magnitude of num	*/
		 double *fracp)		/* output - fractional part of num			*/
{
	double magnitude;		/* local variable - magnitude of num		*/

	/* Determines sign of num */
	if (num < 0)
		*signp = '-';
	else if (num == 0)
		*signp = ' ';
	else
		*signp = '+';
	
	/* Find magnitude of num (its absolute value) and 
	   separates it into whole and fractional parts			*/
	magnitude = fabs(num);
	*wholep = floor(magnitude);
	*fracp = magnitude - *wholep;
}