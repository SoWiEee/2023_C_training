#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void two_winnner(double percentage[], char* e, char* t);                               /*void the function to calculate when there is no absolute winner*/

int main()
{
	int table[5][4] = { {192,48,206,37},{147,90,312,21},{186,12,121,38},{114,21,408,39},{267,13,382,29} }; /*difine the table data*/
	int row, column, total_vote[4];                                                    /*the row and column of the table, the total votes of each candidates*/
	double percentage[4], all;                                                         /*the percentage of each canidate's vote, the total votes of every candidates*/
	for (int i = 1; i <= 2; i++)                                                       /*do the loop two times for two cases*/
	{
		for (int k = 0; k < 4; k++)                                                    /*do the loop to make each data equals to 0 at first*/
		{
			total_vote[k] = 0;
			percentage[k] = 0;
		}
		row = 0; column = 0,all=0;

		printf("\ncase %d:\n", i);                                                     /*print out the table*/
		printf("\t\tCandidate\tCandidate\tCandidate\tCandidate\n");
		printf("Precinct\t    A\t\t    B\t\t    C\t\t   D\n");
		printf("    1\t           192\t\t   48\t\t   206\t\t  37\n");
		printf("    2\t           147\t\t   90\t\t   312\t\t  21\n");
		printf("    3\t           186\t\t   12\t\t   121\t\t  38\n");
		printf("    4\t           114\t\t   21\t\t   %d\t\t  39\n",table[3][2]);
		printf("    5\t           267\t\t   13\t\t   382\t\t  29\n");

		for (char n = 'A'; n <= 'D'; n++)                                             /*do the loop four times for four cases*/
		{
			for (row = 0; row < 5; row++)                                             /*do the loop five times to sum up five votes of each candidate's data*/
			{
				total_vote[column] += table[row][column];
			}
			printf("The total number of the votes for candidate %c is %d.\n", n, total_vote[column]); /*print out each total votes of the candidates*/
			column++;
		}
		for (column = 0; column < 4; column++)                                        /*do the loop four times to sum up four total votes*/
		{
			all += total_vote[column];
		}
		
		for (column = 0; column < 4; column++)                                        /*do the loop four times to calculate each candidate's percentage*/
		{
			percentage[column] = total_vote[column] / all;
		}
		column = 0;
		for (char n = 'A'; n <= 'D'; n++)                                             /*print out each percentage of the candidates*/
		{
			printf("The percentage of the total votes for candidate %c is %.5f.\n", n, percentage[column]);
			column++;
		}
		column = 0;
		bool no_winner = true;
		for (column = 0; column < 4; column++)                                        /*do the loop four times to check four candidate's result*/
		{
			if (percentage[column]>=0.5)                                              /*if any candidate's percentage is bigger than 0.5, he or she is the winner*/
			{
				switch (column)
				{
				case 0:printf("The winner is candidate A!\n\n"); break;
				case 1:printf("The winner is candidate B!\n\n"); break;
				case 2:printf("The winner is candidate C!\n\n"); break;
				case 3:printf("The winner is candidate D!\n\n"); break;
				}
				no_winner = false;
			}
		}
		if (no_winner)                                                                /*if no one gets 0.5, print out the first and second to participate the runoff*/
		{
			char e, t;
			two_winnner(percentage, &e, &t);                                          /*call the function to calculate the first and the second*/
			if (e > t)                                                                /*make the letter sort in right order*/
			{
				int change;
				change = e;
				e = t;
				t = change;
			}
			printf("Candidate %c and Candidate %c should participate a runoff.\n\n", e, t); /*print out which two candidate should participate a runoff*/
		}

		table[3][2] = 108;                                                            /*change the '408' into '108'*/
	}
	system("PAUSE");
	return(0);
}

void two_winnner(double percentage[],char *e,char *t)
{
	int column=0;
	for (int i = 1; i < 4; i++)                                                       /*compare each percentage and get the largest data that shows the first candidate*/
	{
		if (percentage[column] < percentage[i])
		{
			column = i;
		}
	}
	percentage[column] = 0;                                                           /*make the largest data into 0 so that the next largest data shows the second candidate*/
	switch(column)
	{
		case 0:*e = 'A'; break;                                                       /*switch cases to return the first candidate*/
		case 1:*e = 'B'; break;
		case 2:*e = 'C'; break;
		case 3:*e = 'D'; break;
    }
	column = 0;
	for (int i = 1; i < 4; i++)
	{
		if (percentage[column] < percentage[i])                                       /*compare each percentage and get the largest data that shows the second candidate*/
		{
			column = i;
		}
	}
	switch (column)
	{
	case 0:*t = 'A'; break;                                                           /*switch cases to return the second candidate*/
	case 1:*t = 'B'; break;
	case 2:*t = 'C'; break;
	case 3:*t = 'D'; break;
	}
}