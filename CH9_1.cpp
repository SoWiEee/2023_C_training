#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int  blob_check(int pixels[5][5],int x,int y)                                //run the function to count how much blob is there
{
	int count = 1;
	if (x < 5 && y < 5 && x >= 0 && y >= 0) 
	{
		if (pixels[x][y] == 0)
		{
			return(0);
		}
		else if (pixels[x][y] == 1)
		{
			pixels[x][y] = 0;
			for (int i = -1; i <= 1; i++)
			{
				for (int j = -1; j <= 1; j++)
				{
					count+=blob_check(pixels, x + i, y + j); 
				}
			}
		}
	}
	else
	{
		return(0);
	}
	return(count);
}

int main()
{
	int pixels[5][5] = { {1,1,0,0,0},{0,1,1,0,0},{0,0,1,0,1},{1,0,0,0,1},{0,1,0,1,1} };  //define the pixels
	int x, y,change;

	printf("y\n");                                                                       //print out the pixels
	for (int i = 0; i < 5; i++)
	{
		printf("%d", 4 - i);
		for (int j = 0; j < 5; j++)
		{
			if (pixels[i][j] == 1)
			{
				printf("¡½");
			}
			else
			{
				printf("¡¼");
			}
		}
		printf("\n");
	}
	for (int i = 0; i < 5; i++)
	{
		printf("%2d", i);
	}
	printf(" x\n\n");

	printf("Enter the (x , y) yo want to count of the pixels belongings =>");           //prompt the user to enter which blob he or she wants to began the count
	scanf("%d%d", &x, &y);                                                              //change the (x,y)of the pixels into computer's (x,y)

	change = x;
	x = y;
	y = change;
	x = 4 - x;

	printf("The count of the pixels belongings is %d.\n", blob_check(pixels, x, y));   //print out how many it counts

	system("PAUSE");
	return(0);
}