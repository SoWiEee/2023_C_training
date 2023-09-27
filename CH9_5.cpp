#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void path(char array[8][8],int road[8][8], int x, int y)                             //run the maze and print out all steps you walk
{ 
	if (x <= 7 && y <= 7)
	{
	    if (x == 7 && y == 7)
	    {
			for (int j = 0;j <= 7; j++)
			{
				for (int i = 0; i <= 7; i++)
				{
					if (road[i][j] == 1)
					{
						printf("(%d ,%d)->", i, j);
					}
				}
			}
			printf("(7 , 7)\n\n");
			return;
	    }

		road[x][y] = 1;

		if (x < 7)
		{
			if (array[x+1][y] == ' ')
			{
				path(array,road, x+1, y);
			}
		}
		if (y < 7)
		{
			if (array[x][y+1] == ' ')
			{
				path(array,road, x, y+1);
			}
		}
		if (array[x + 1][y] == 'X' && array[x][y + 1] == 'X' || array[x + 1][y] == 'X' && y == 7 || array[x][y + 1] == 'X' && x == 7)
		{
			for (int j = 0; j <= 7; j++)
			{
				for (int i = 0; i <= 7; i++)
				{
					if (road[i][j] == 1)
					{
						printf("(%d ,%d)->", i, j);
					}
				}
			}
			printf("There is no road already.\n\n"); 
		}
		road[x][y] = 0;
	}
	
}

int main()
{
	char array[8][8] = { { ' ', ' ', ' ', ' ', 'X', 'X', ' ', 'X'}, { 'X', ' ', 'X', ' ', 'X', 'X', 'X', ' '}, { 'X', ' ', ' ', 'X', 'X', ' ', ' ', ' '}, { 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X'}, { ' ', ' ', 'X', ' ', ' ', 'X', 'X', 'X'}, { 'X', ' ', ' ', ' ', 'X', 'X', ' ', ' '}, { 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' '}, { 'X', ' ', 'X', ' ', 'X', 'X', ' ', ' '} };
	int road[8][8] = {};
	int x = 0, y = 1;

	printf("\n");
	for (int i = 0; i <= 7; i++)                                    //print out the maze
	{
		printf("%2d", i);
	}
	printf(" y\n");
	for (int i = 0; i <= 7; i++)
	{
		printf("%d", i);
		for (int j = 0; j <= 7; j++)
		{
			if (array[i][j] == ' ')
			{
				printf("¡¼");
			}
			else
			{
				printf("¡½");
			}
		}
		printf("\n");
	}
	printf("x\n\n\n");
	

	path(array,road, 0, 1);                                        //run the maze and print out all steps you walk

	system("PAUSE");
	return(0);
}