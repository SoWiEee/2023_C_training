/*
 * Reads serial number and displays class of ship.
 */
#include <stdio.h>
#include <stdlib.h>

void determineClass(char);		//determine class of ship

int main()
{
	char class_ID;				//input - character indicating class of ship

	//read first character of serial number
	printf("Enter ship serial number> ");		
	scanf("%c", &class_ID);
	
	//determine class of ship then print first character and ship class
	determineClass(class_ID);

	system("PAUSE");
	return 0;
}


void determineClass(char ID) {
	switch (ID)
	{
		case 'B':
		case 'b':
			printf("Ship class is %c: Battle Ship\n",ID);
			break;
		case 'C':
		case 'c':
			printf("Ship class is %c: Cruiser\n", ID);
			break;
		case 'D':
		case 'd':
			printf("Ship class is %c: Destroyer\n", ID);
			break;
		case 'F':
		case 'f':
			printf("Ship class is %c: Frigate\n", ID);
			break;
		default:
			printf("Ship class is %c: Unknown\n", ID);
	}
}