#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BASEUSEHOUR		10.0	/* base use hour								*/
#define BASERATE		7.99	/* based rate for based use hour				*/
#define ADDITIONALRATE	1.99	/* additional rate per hour exceeding 10 hours	*/

void charges(double useHour, double *totalCharge, double *averageCost);
double round_money(double money);

int main(void)
{
	FILE *inputFile;		/* pointer to input files						*/
	FILE *outputFile;		/* pointer to output files						*/
	int month;				/* input - current month						*/
	int year;				/* input - current year							*/
	int input_status;		/* status value returnen by fscanf				*/
	int customer;			/* input - customer number						*/
	double useHour;			/* input - hours customer used					*/
	double totalCharge;		/* output - money that customer need to pay		*/
	double averageCost;		/* output - average pay for every hour			*/

	/*Prepare files for input file */
	inputFile = fopen("usage.txt", "r");

	/* check input file exists */
	if (!inputFile)
	{
		printf("input file no exist.\n");
		system("pause");
		exit(1);
	}

	/* Prepare files for output file */
	outputFile = fopen("charges.txt", "w");

	/* Read header from input file and write header to output file */
	input_status = fscanf(inputFile, "%d %d", &month, &year);
	if (input_status < 2)
	{
		printf("Input error - please check header of inout file.\n");
		system("pause");
		exit(1);
	}
	else {
		fprintf(outputFile, "Charges for %d/%d\n\n", month, year);
		fprintf(outputFile, "Customer\tHours used\tCharge per hour\tAverage cost\n");
	}

	/*Input each item, compute and write*/
	input_status = fscanf(inputFile, "%d %lf", &customer, &useHour);
	while (input_status != EOF)
	{
		charges(useHour, &totalCharge, &averageCost);
		fprintf(outputFile, "%d %15.1f %15.2f %15.2f\n", customer, useHour, totalCharge, averageCost);
		input_status = fscanf(inputFile, "%d %lf", &customer, &useHour);
	}
	
	printf("Compute finishing.\n");

	/*Close the files*/
	fclose(inputFile);
	fclose(outputFile);

	system("pause");
	return 0;
}

/* Compute total charge and average cost */
void charges(double useHour,		/* input - used hour				*/
			 double *totalCharge,	/* output - total pay				*/
			 double *averageCost)	/* output - average pay per hour	*/
{
	/* use exceeding 10 hours, pay more money */
	if (useHour <= BASEUSEHOUR)
	{
		*totalCharge = BASERATE;
		*averageCost = round_money(*totalCharge / useHour);
	}
	else
	{
		*totalCharge = BASERATE + ceil(useHour - BASEUSEHOUR)*ADDITIONALRATE;
		*averageCost = round_money(*totalCharge / useHour);
	}
}

/*Round money to nearest cent*/
double round_money(double money)
{
	return floor(money * 100 + 0.5) / 100;
}