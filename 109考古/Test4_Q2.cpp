#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<io.h>

double sumN(int n);

int main()
{
	FILE *binaryOutput, *binaryInput;		/* file pointers for input and backup files */
	int integers[4] = {3, 6, 10, 11};		/* numbers will output						*/
	int number;								/* read a integer from file					*/
	int index;								/* loop index								*/
	int sum;								/* sumation from 1 to any integer			*/
	int step;								/* printing controller						*/
	
	/* open output file																	*/
	binaryOutput = fopen("input.bin", "wb");
	/* write 4 integers to output file													*/
	for (index = 0; index < 4; index++)
	{
		/* write an integer to file														*/
		fwrite(&integers[index], sizeof(int), 4, binaryOutput);
	}
	/* close output file																*/
	fclose(binaryOutput);

	/* open input file																	*/		
	binaryInput = fopen("input.bin", "rb");
	/* read an integer from input file, calculate sumatiom from 1 to it and print		*/
	for (index = 0; index < 4; index++)
	{
		/* read an integer from input file												*/
		fread(&number, sizeof(int), 1, binaryInput);
		/* calculate sumaiton															*/
		sum = sumN(number);
		/* print controller																*/
		step = 1;
		printf("%d", step);
		/* print 1+2+...+number															*/
		while (step < number)
		{
			printf("+%d", step+1);
			step++;
		}
		printf("=%d\n", sum);
	}
	/* close input file																	*/	
	fclose(binaryInput);

	system("pause");
	return 0;
}

double sumN(int n)	/* input - calculate sumation from 1 to n							*/
{
	if (n == 1)
	{
		return 1;				/* simple case											*/
	}
	else if (n > 1)
	{
		return n + sumN(n - 1);	/* recursive step										*/
	}
}
