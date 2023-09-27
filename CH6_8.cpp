#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void charges(double hours_used, double* per_hour, double* average_cost);  /*void the function "charges"*/
void round_money(double* average_cost);                                   /*voidfunction "round_money"*/
int main()
{
	int month, year, customer_number;           /*month, year, customer number for the data, */
	double hours_used, per_hour, average_cost;  /*hours used, charges per hour, average cost for the data*/

	FILE* usage_input;                               /*define the file "usage"*/
	FILE* charges_output;                            /*define the file "charges"*/
	usage_input = fopen("usage.txt", "r");           /*open the file "usage.txt" refers to the file "usage", and "read" data from the file*/
	charges_output = fopen("charges.txt", "w");      /*open the file "charges.txt" refers to the file "charges", and "write" data to the file*/

	if (usage_input == NULL)                         /*if the file "usage.txt" can't open ,tell the user and end the program*/
	{
		printf("Fail to open usage.");
		return(0);
	}
	if (charges_output == NULL)                      /*if the file "charges.txt" can't open ,tell the user and end the program*/
	{
		printf("Fail to open charges.");
		return(0);
	}
	fscanf(usage_input, "%d%d", &month, &year);                                                    /*input data "month" and "year" from the file "usage.txt"*/
	fprintf(charges_output, "\nCharges for %d/%d\n\n", month, year);                               /*print out month and year to the file "charges.txt"*/

	fprintf(charges_output, "Customer     Hours used     Charge per hour    Average cost\n");      /*print out title to the file "charges.txt"*/

	while (fscanf(usage_input, "%d", &customer_number) != EOF)   /*while the scan of the file data "customer number" isn't "\n"
															 , which cause the scan of the "%d" returns '-1', run the loop*/  /*EOF=-1*/
	{
		fscanf(usage_input, "%lf", &hours_used);                            /*scan the data "hours used" from the file "usage.txt"*/
		charges(hours_used, &per_hour, &average_cost);     /*do the function "charges"*/
		round_money(&average_cost);

		/*print out data to the file "charges.txt"*/
		fprintf(charges_output, "  %d        %.1f             %.2f              %.2f\n\n", customer_number, hours_used, per_hour, average_cost);

	}
	fclose(usage_input);        /*close the file "usage.txt"*/
	fclose(charges_output);     /*close the file "charges.txt"*/

	system("PAUSE");
	return(0);
}
void charges(double hours_used, double* per_hour, double* average_cost)      /*function "charges"*/
{
	/*calculate the charges per hour*/
	if (hours_used <= 10)
	{
		*per_hour = 7.99;
	}
	else if (hours_used >= 10)
	{
		*per_hour = 7.99 + 1.99 * (ceil(hours_used) - 10);
	}
	/*calculate the average cost*/
	*average_cost = *per_hour / hours_used;
}

void round_money(double* average_cost)                                       /*function "round_money"*/
{
	int two_decimal;

	two_decimal = *average_cost * 100 + 0.5;
	*average_cost = (double)two_decimal / 100;
}