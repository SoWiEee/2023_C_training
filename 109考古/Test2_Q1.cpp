#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void separate(double num, char *signp, int *wholep, double *fracp);

int main(void)
{
	FILE *inputFile;	/* pointer to input file						*/
	double value;		/* input - number to analyze					*/
	char sn;			/* output - sign of value						*/
	int whl;			/* output - whole number magnitude of value		*/
	double fr;			/* output - fracrional part of value			*/
	int input_status;	/* status value returnen by fscanf				*/
	char discard;		/* unprocessed character from input file		*/

	/* Prepare file for input */
	inputFile = fopen("number.txt", "r");

	/* check input file exist */
	if (inputFile == NULL)
	{
		printf("input file no exist.\n");
		system("pause");
		exit(1);
	}

	/* Input each item and print results */
	do
	{
		/* input an item from input file */
		input_status = fscanf(inputFile, "%lf", &value);

		/* handle the invalid input, or separate input value */
		if (input_status == 0)
		{
			printf("invalid input\n");
			/* discard invalid input */
			do
			{
				fscanf(inputFile, "%c", &discard);
			} while (discard != '\n');
		}
		else if (input_status == 1)
		{
			/* separate input value and print result */
			separate(value, &sn, &whl, &fr);
			printf("Parts of %.2f\n sign: %c\n", value, sn);
			printf(" whole number magnitude: %d\n", whl);
			printf(" fractional part: %.2f\n", fr);
		}
			
	} while (input_status != EOF);

	
	/* close file */
	fclose(inputFile);

	system("pause");
	return(0);
}

/*
 *Separate anumber into three parts: a sign (+, - or blank),
 *a whole number magnitude, and a fractional part
 */
void 
separate(double num,		/* input - valu of split					*/
		 char *signp,		/* outpu - sign of num						*/
		 int *wholep,		/* output - whole number magnitude of num	*/
		 double *fracp)		/* output - fractional part of num			*/
{
	double magnitude;		/* local variable - magnitude of num		*/

	/* determine sign of num */
	if (num < 0)
		*signp = '-';
	else if (num == 0)
		*signp = ' ';
	else
		*signp = '+';
	
	/* Find magnitude of num (its absolut value) and 
	   separate it into whole and fractional parts			*/
	magnitude = fabs(num);
	*wholep = floor(magnitude);
	*fracp = magnitude - *wholep;
}