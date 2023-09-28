/*
 * Read a ship's serial number and displays the class of the ship
 */
 
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char class_ID;    /* input - the first character indicating class of ship */

	/* Read the first letter of a ship's serial number. */
	printf("Enter the ship serial number> ");		
	scanf("%c", &class_ID);
	
	/* Display the first character and a message indicating the class of the ship */
	switch (class_ID)
	{
		case 'B':
		case 'b':
			printf("Ship class is %c: Battle Ship\n",class_ID);
			break;
		case 'C':
		case 'c':
			printf("Ship class is %c: Cruiser\n", class_ID);
			break;
		case 'D':
		case 'd':
			printf("Ship class is %c: Destroyer\n", class_ID);
			break;
		case 'F':
		case 'f':
			printf("Ship class is %c: Frigate\n", class_ID);
			break;
		default:
			printf("Ship class is %c: Unknown\n", class_ID);
	}

	system("PAUSE");
	return 0;
}