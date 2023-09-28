#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* car sale data from 2009 to 2012 */
const int car[3][4] = { {210,326,250,264},
						{196,214,258,396},
						{184,276,320,316} };

int main(void)
{
	int i, j;						/* use in for-loop as an index										*/
	int num_TOYOTA = 0;				/* total number of car sold for TOYOTA								*/
	int num_BMW = 0;				/* total number of car sold for BMW									*/
	int num_LEXUS = 0;				/* total number of car sold for LEXUS								*/
	int num_2009 = 0;				/* annual number of car sale for 2009								*/
	int num_2010 = 0;				/* annual number of car sale for 2010								*/
	int num_2011 = 0;				/* annual number of car sale for 2011								*/
	int num_2012 = 0;				/* annual number of car sale for 2012								*/
	int highest_num = 0;			/* the highest number of car sale within 2009 to 2012				*/
	char brand_of_highest_num[10];	/* the brand of the highest number of car sale within 2009 to 2012	*/
	int year_of_highest_num;		/* the year of the highest number of car sale within 2009 to 2012	*/

	/* calculate num_TOYOTA and print it */
	for (i = 0; i < 4; i++) {
		num_TOYOTA += car[0][i];
	}
	printf("Total number of car sold for TOYOTA is %d.\n", num_TOYOTA);

	/* calculate num_BMW and print it */
	for (i = 0; i < 4; i++) {
		num_BMW += car[1][i];
	}
	printf("Total number of car sold for BMW is %d.\n", num_BMW);

	/* calculate num_LEXUS and print it */
	for (i = 0; i < 4; i++) {
		num_LEXUS += car[2][i];
	}
	printf("Total number of car sold for LEXUS is %d.\n", num_LEXUS);

	/* find the sale champion within 2009 to 2012 and print its sale number */
	if (num_TOYOTA >= num_BMW&&num_TOYOTA >= num_LEXUS)
		printf("Sale champion is TOYOTA and its sale number is %d.\n", num_TOYOTA);
	else if (num_BMW >= num_TOYOTA&&num_BMW >= num_LEXUS)
		printf("Sale champion is BMW and its sale number is %d.\n", num_BMW);
	else
		printf("Sale champion is \"LEXUS\" and its sale number is %d.\n", num_LEXUS);
	printf("\n");

	/* calculate num_2009 and print it */
	for (i = 0; i < 3; i++) {
		num_2009 += car[i][3];
	}
	printf("Annual number of car sold for 2009 is %d.\n", num_2009);

	/* calculate num_2010 and print it */
	for (i = 0; i < 3; i++) {
		num_2010 += car[i][2];
	}
	printf("Annual number of car sold for 2010 is %d.\n", num_2010);

	/* calculate num_2011 and print it */
	for (i = 0; i < 3; i++) {
		num_2011 += car[i][1];
	}
	printf("Annual number of car sold for 2011 is %d.\n", num_2011);

	/* calculate num_2012 and print it */
	for (i = 0; i < 3; i++) {
		num_2012 += car[i][0];
	}
	printf("Annual number of car sold for 2012 is %d.\n", num_2012);

	/* find the highest annual number and its year */
	if (num_2009 >= num_2010&&num_2009 >= num_2011&&num_2009 >= num_2012)
		printf("Highest annual number %d and its year is \"2009\".\n", num_2009);
	else if(num_2010 >= num_2009&&num_2010 >= num_2011&&num_2010 >= num_2012)
		printf("Highest annual number %d and its year is \"2010\".\n", num_2010);
	else if (num_2011 >= num_2009&&num_2011 >= num_2010&&num_2011 >= num_2012)
		printf("Highest annual number %d and its year is \"2011\".\n", num_2011);
	else
		printf("Highest annual number %d and its year is \"2012\".\n", num_2012);
	printf("\n");

	/* calculate highest_num and print it with the brand and year */
	for (i = 0; i < 3; i++)
		for (j = 0; j < 4; j++)
			if (highest_num < car[i][j]) {
				highest_num = car[i][j];
				if (i == 0)
					strcpy(brand_of_highest_num, "TOYOTA");
				else if (i == 1)
					strcpy(brand_of_highest_num, "BMW");
				else
					strcpy(brand_of_highest_num, "LEXUS");
				if (j == 3)
					year_of_highest_num = 2009;
				else if (j == 2)
					year_of_highest_num = 2010;
				else if (j == 1)
					year_of_highest_num = 2011;
				else
					year_of_highest_num = 2012;
			}
	printf("Highest number of car sale is %d and its brand is \"%s\", year is \"%d\".\n", highest_num, brand_of_highest_num, year_of_highest_num);

	system("pause");
	return 0;
}