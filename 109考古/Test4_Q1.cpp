#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXROW 8			/* maximum row in maze			*/
#define MAXCOLUMN 8			/* maximum column in maze		*/
#define START_X 0			/* x coordinate of start point	*/
#define START_Y 0			/* y coordinate of start point	*/
#define END_X 7				/* x coordinate of end point	*/
#define END_Y 7				/* y coordinate of end point	*/

typedef struct Point{
	int x;
	int y;
}Point;

/* MAZE1 */
char MAZE1[MAXROW][MAXCOLUMN] = { 
{ ' ',' ',' ','X',' ',' ',' ','X' },
{ ' ','X',' ',' ',' ','X',' ',' ' },
{ ' ',' ','X','X',' ',' ','X',' ' },
{ 'X',' ','X',' ','X',' ',' ',' ' },
{ ' ',' ','X','X','X',' ','X',' ' },
{ ' ','X',' ',' ',' ',' ',' ',' ' },
{ ' ','X',' ','X',' ','X',' ','X' },
{ ' ',' ',' ','X',' ',' ',' ',' ' }};

/* MAZE2 */
char MAZE2[MAXROW][MAXCOLUMN] = {
{ ' ',' ',' ','X',' ',' ',' ','X' },
{ ' ','X',' ',' ',' ','X',' ',' ' },
{ ' ',' ','X','X',' ',' ','X',' ' },
{ 'X',' ','X',' ','X',' ',' ',' ' },
{ ' ',' ','X','X','X',' ','X',' ' },
{ ' ','X',' ',' ',' ',' ',' ',' ' },
{ ' ','X',' ','X',' ','X',' ','X' },
{ ' ',' ',' ','X',' ',' ','X',' ' }};

void move(char maze[MAXROW][MAXCOLUMN], int pre_X, int pre_Y, int *nop, Point pathList[], int listLength);
void printMaze(char maze[MAXROW][MAXCOLUMN], int* nop);
void printPath(Point pointList[], int listLength);
void existPath(int *path);

int main()
{
	int path = 0;							/* output - number of feasible path			*/
	Point pointList[MAXCOLUMN*MAXROW];		/* output - point list						*/
	int listLength = 0;						/* length of list filled point coordinate	*/

	printf("find MAZE1\n");
	/* find feasible path in MAZE1																	*/
	move(MAZE1, START_X, START_Y, &path, pointList, listLength);
	existPath(&path);

	/* initialize path and list length																*/
	path = 0;
	listLength = 0;
	printf("find MAZE2\n");
	/* find feasible path in MAZE2																	*/
	move(MAZE2, START_X, START_Y, &path, pointList, listLength);
	existPath(&path);

	system("pause");
	return 0;
}

void move(char maze[MAXROW][MAXCOLUMN], /* input - maze												*/
		  int pre_X,					/* input - x coordinate of current point					*/
		  int pre_Y,					/* input - y coordinate of current point					*/ 
		  int *path,					/* output - number of path									*/
		  Point pointList[],			/* output - point list in feasoble path						*/
		  int listLength)				/* length of list filled point coordinate					*/
{
	/* mark current point using 'o'																	*/
	maze[pre_Y][pre_X] = 'o';
	/* add current point into list, and list length added by 1										*/
	pointList[listLength].x = pre_X;
	pointList[listLength].y = pre_Y;
	listLength++;

	if (pre_Y == END_Y && pre_X == END_Y)	/* current point is end point							*/
	{
		(*path)++;							/* increase number of path								*/
		printMaze(maze, path);				/* print maze and track									*/
		printPath(pointList, listLength);	/* print coordinate of track							*/
	}
	else
	{
		if (maze[pre_Y][pre_X+1] == ' ' && pre_X+1 < MAXCOLUMN)	/* move east						*/
		{
			move(maze, pre_X+1, pre_Y, path, pointList, listLength);
		}
		if (maze[pre_Y+1][pre_X] == ' ' && pre_Y+1 < MAXROW)	/* move south						*/
		{
			move(maze, pre_X, pre_Y+1, path, pointList, listLength);
		}
		if (maze[pre_Y][pre_X-1] == ' ' && pre_X-1 >= 0)		/* move west						*/
		{
			move(maze, pre_X-1, pre_Y, path, pointList, listLength);
		}
		if (maze[pre_Y-1][pre_X] == ' ' && pre_Y-1 >= 0)		/* move north						*/
		{
			move(maze, pre_X, pre_Y-1, path, pointList, listLength);
		}
	}
	/* don't move, erase mark																		*/
	maze[pre_Y][pre_X] = ' ';
	/* delete current point from list tail*/
	listLength--;
}

void printMaze(char maze[MAXROW][MAXCOLUMN],	/* input - maze										*/
			   int* path)						/* output - numbers of path							*/	
{
	int i, j; /* loop index */
	
	printf("No.%d path\n", *path);
	/* print maze																					*/		
	for (i = 0; i < MAXROW; i++)
	{
		for (j = 0; j < MAXCOLUMN; j++)
		{
			printf("%c", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void printPath(Point pointList[], int listLength)	/* input - pointer of first point in list						*/
{
	/* print every point in feasible path															*/
	int index = 0;
	printf("(%d,%d)", pointList[index].x, pointList[index].y);
	index++;
	while (index < listLength)
	{
		printf("->(%d,%d)", pointList[index].x, pointList[index].y);
		index++;
	}
	printf("\n\n\n\n");
}

void existPath(int *path)/* input - number of path													*/
{
	/* print information of path found																*/
	if ((*path) == 0)
	{
		printf("There is no path in this maze\n\n");
	}
	else
	{
		printf("There are %d paths\n\n", *path);
	}
}