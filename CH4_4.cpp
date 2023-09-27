#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(void){
	char color;

	printf("Enter the Cylinder colors =>");       /*enter color for the associate content*/
	scanf("%c", &color);


	/*scan different cases and output the result of the associate content*/
	switch (color){
	case 'O':
	case 'o':
		printf("The associated content is ammnonia.");        /*in case "orange" ,the program will output a result "ammonia"*/
		break;

	case 'B':
	case 'b':
		printf("The associated content is  monoxide.");
		break;

	case 'Y':
	case 'y':
		printf("The associated content is hydrogen.");
		break;

	case 'G':
	case 'g':
		printf("The associated content is oxygen.");
		break;

	default:
		printf("Unknown");
		break;
	}

	system("pause");
	return 0;
}
