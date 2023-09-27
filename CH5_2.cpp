#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

int sum(char digit)
{
	int sum=0;                                  /*the sum of each numeric value*/ /*'sum=0' => give sum a begin value*/

	while (digit != '\n')                       /*while the scan of the digit is not 'enter',it will run the loop*/
	{
		sum = sum + ((int)digit - (int)'0');    /*the sum will plus the numeric value each round*/
		scanf("%c", &digit);                    /*scan next letter*/
	}
	return(sum);
}

int main()
{
	char digit;

	printf("Emter letters =>");                      /*input the letter*/
	scanf("%c", &digit);

	printf("The total value is =>%d",sum(digit));    /*output the result*/

	system("PAUSE");
	return(0);

}