#define _CRT_SECURE_NO_WARNINGS
//Ignore old and unsafe functions, written in front of the code
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char shipid; //define ship ID
	printf("Enter the ship ID :");
	scanf("%c", &shipid);         //Enter the ship ID
	switch (shipid)
	{
	case 'B':
	case 'b':
		printf("The ship is Battle Ship");
		break;
	case 'C':
	case 'c':
		printf("The ship is Cruiser");
		break;
	case 'D':
	case 'd':
		printf("The ship is Destroyer");
		break;
	case 'F':
	case 'f':
		printf("The ship is Frigate");
		break;
	default:
		printf("Not find!!!");
	}
	system("PAUSE");
	return 0;
}