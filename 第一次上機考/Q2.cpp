/*
*	First use keyboard to key in value,and store in 'a','b','c'.
*	Then display the three value.
*	Switch the value of 'a' and 'b',and display 'a','b' values.
*	Used 'findMax' function to find maximum value of the three values,
*	and 'avgABC' function to compute average of the three values.
*/

#define _CRT_SECURE_NO_WARNINGS	//Use 'scanf' function.
#include <stdio.h>				//Include library.
#include <stdlib.h>

double findMax(double, double, double);	//Find maximum value of the three values. 
double avgABC(double, double, double);	//Compute average value of the three values.

int main() {
	double a, b, c;	//'a','b','c' stored value from keyboard.
	double swap;	//'swap' used for temporary storage.

	printf("Please key in value was stored in 'a':\n");
	scanf("%lf", &a);	//Key in 'a' value.
	printf("Please key in value was stored in 'b':\n");
	scanf("%lf", &b);	//Key in 'b' value.
	printf("Please key in value was stored in 'c':\n");
	scanf("%lf", &c);	//Key in 'c' value.

	printf("\nUser input a = %.2f, b = %.2f, and c = %.2f.\n", a, b, c);

	swap = a;	//'swap' temporary storage value of 'a'.
	a = b;		//'a' stored value of 'b'.
	b = swap;	//'b' stored value of 'swap'.

	printf("After switching, a = %.2f, b = %.2f.\n", a, b);	//Display after switch the value of 'a' and 'b'.
	printf("The maximum value is %.2f.\n", findMax(a, b, c));//Display maximum value.
	printf("The average values is %.2f.\n", avgABC(a, b, c));//Display average value.

	system("pause");
	return 0;
}

/*'findMax' function : Find maximum value of the three values.*/
double findMax(double a, double b, double c) {
	if (a >= b && a >= c) {
		//Find 'a' value is maximum
		return a;
	}
	else {
		//'b' or 'c' value have a one maximum value.
		if (b >= c) {
			//find 'b' value is maximum.
			return b;
		}
		else {
			//find 'c' value is maximum.
			return c;
		}
	}
}

/*'avgABC' function : Compute average value of the three values.*/
double avgABC(double a, double b, double c) {
	return (a + b + c) / 3;
}