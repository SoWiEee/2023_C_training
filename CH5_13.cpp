#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


int main()
{
	int number,    /*the number of the player*/
		player=1;  /*int a condition for the loop*/

	char record;   /*the record of the player*/

	FILE* batting;                                    /*call a File*/
	batting = fopen("batting_record.txt","r");        /*open the File*/ /*"r" =>read the File*/
	 
	for (player =1;player<4;++player)                 /*player is 1 in the beginning; if player < 4 then run the loop; player +1 each round*/
	{
		double average = 0,    /*the batting average*/
			hit = 0,           /*the 'H' in the record you input*/
			hit_and_out = 0;   /*the 'H' and 'O' in the record you input*/

		if (batting == NULL)  /*if the file can't open, print to tell the user and end the program*/
		{
			printf("Fail to open File.");
			return(0);
		}
		fscanf(batting,"%d", &number);            /*scan the number of the player in the file*/
		fscanf(batting, "%c", &record);           /*scan the reecord of the player in the file*/

		printf("\n\nPlayer %d's record:", number); /*print out which player's record it is*/
		while (record != '\n')                     /*while the scan of the record isn't 'enter', run the loop*/
		{
			printf("%c", record);                  /*print out the record letter one by one during the loop*/
			switch (record)                        /*switch cases of the scan "record" and do the steps*/
			{
			case'H':
			case'h':
				hit = hit + 1;
				hit_and_out = hit_and_out + 1;
				break;
			case'O':
			case'o':
				hit_and_out = hit_and_out + 1;
				break;
			default:
				break;
			}

			fscanf(batting, "%c", &record);        /*scan the next letter of the record in the file*/

		}
		average = hit / hit_and_out;               /*calculate the average*/

		printf("\nPlayer %d's batting average: %.3f\n", number, average);       /*print out the batting average of each player*/
	}
	
	fclose(batting);                               /*close the File*/

	system("PAUSE");
	return(0);
	
}
