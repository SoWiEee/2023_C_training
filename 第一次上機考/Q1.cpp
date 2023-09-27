/*
 *	First time,the program will be asked to select the class of
 *	the ship in the list.
 *	However using 'switch' to Discriminant your option,and print
 *	the class of the ship in the window.
*/

#define _CRT_SECURE_NO_WARNINGS	//Use 'scanf' function
#include <stdio.h>				//Include library
#include <stdlib.h>

int main() {	//Main program

	char ship_num;	//Save 'scanf' function value

	/*Display all class of the ship*/
	printf("Please key in a ship number:\n");
	printf("classID\tShipClass\n");
	printf("B or b\tBattle Ship\n");
	printf("C or c\tCruiser\n");
	printf("D or d\tDestroyer\n");
	printf("F or f\tFrigate\n");

	scanf("%c", &ship_num);	//Read keyboard key in

	switch (ship_num){	//Which class start to open
		case 'B':	//Battle Ship
		case 'b':
			printf("You chose class of ship is 'Battle Ship'.");
			break;
		case 'C':	//Cruiser
		case 'c':
			printf("You chose class of ship is 'Cruiser'.");
			break;
		case 'D':	//Destroyer
		case 'd':
			printf("You chose class of ship is 'Destroyer'.");
			break;
		case 'F':	//Frigate
		case 'f':
			printf("You chose class of ship is 'Frigate'.");
			break;
		default:	//No this one
			printf("Sorry,class '%c' isn't in the list!", ship_num);
			break;
	}
	printf("\n");

	system("pause");	//Please 'pause' and return
	return 0;
}