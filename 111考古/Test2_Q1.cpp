/*
 * prompt a user to input two fraction and one operator
 * to compute n1/d1 op n2/d2
 * finally, reduce the result and print it on console
 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

char scan_OP();
void scan_fraction(int* nump, int* denomp);
void OP_fractions(char op, int n1, int d1, int n2, int d2, int* n_ansp, int* d_ansp);
void fraction_reduction(int numerator, int denominator, int* n_ansp, int* d_ansp);
int GCD(int a, int b);

int main(void) {
	int n1, d1, n2, d2, n_ans, d_ans;
	char op;

	/* scan two fraction           */
	scan_fraction(&n1, &d1);
	scan_fraction(&n2, &d2);

	/* scan the operator           */
	op = scan_OP();

	/* conput n1/d1 op n2/d2       */
	OP_fractions(op, n1, d1, n2, d2, &n_ans, &d_ans);

	/* reduce the result           */
	fraction_reduction(n_ans, d_ans, &n_ans, &d_ans);

	printf("%d / %d\n", n_ans, d_ans);
	system("PAUSE");
	return 0;
}

/*
 * Get and return a valid operator as its result
 * A valid operator is of this form: '+', '-', '*', and '/'
 */
char scan_OP() {
	char op;               /* input - the operator between two fraction                */
	char discard;          /*         unprocessed character from input line            */
	bool valid = false;    /* check the input value is valid                           */

	/* while loop until user input valid operator                                      */
	while (!valid) {
		printf("Please key in the operator between two fractions('+', '-', '*', or '/'): "); 
		scanf("%c", &op);
		switch (op) {
		case '+':
		case '-':
		case '*':
		case '/':
			valid = true;
			break;
		default:
			printf("Invalid input.\n");
			/* Discard extra input characters*/
			do {
				scanf("%c", &discard);
			} while (discard != '\n');
			valid = false;
			break;
		}
	}

	return op;
}

/*
 * Gets and returns a valid fraction as its result
 * A valid fraction is of this form: integer/positive integer
 * Pre : none
 */
void scan_fraction(int* nump, int* denomp) {
	char slash;      /*         character between numerator and denominator      */
	int status;      /*         status code returned by scanf indicating         
					            number of valid values obtained                  */
	int error;       /*         flag indicating presence of an error             */
	char discard;    /*         unprocessed character from input line            */

	do {
		/* No errors detected yet                                                */
		error = 0;

		/* Get a fraction from the user                                          */
		printf("Enter a common fraction as two integers separated ");
		printf("by a slash> ");
		status = scanf("%d %c%d", nump, &slash, denomp);

		/* Validate the fraction                                                 */
		if (status < 3) {
			error = 1;
			printf("Invalid-please read directions carefully\n");
		}
		else if (slash != '/') {
			error = 1;
			printf("Invalid-separate numerator and denominator by a slash (/)\n");
		}
		else if (*denomp <= 0) {
			error = 1;
			printf("Invalid-denominator must be positive\n");
		}
		/* Discard extra input characters*/
		do {
			scanf("%c", &discard);
		} while (discard != '\n');
	} while (error);
}

/* 
 * Get two fraction and one operator
 * Returns n1/d1 op n2/d2
 */
void OP_fractions(char op, int n1, int d1, int n2, int d2, int* n_ansp, int* d_ansp) {
	switch (op) {
	case '+':
		*n_ansp = n1 * d2 + n2 * d1;
		*d_ansp = d1 * d2;
		break;
	case '-':
		*n_ansp = n1 * d2 - n2 * d1;
		*d_ansp = d1 * d2;
		break;
	case '*':
		*n_ansp = n1 * n2;
		*d_ansp = d1 * d2;
		break;
	case '/':
		*n_ansp = n1 * d2;
		*d_ansp = d1 * n2;
		break;
	default:
		printf("Unknown error.\n");
		printf("Please check the input numbers.\n");
		break;
	}
}

/*
 * Get one fraction
 * Return the fraction after reduced
 */
void fraction_reduction(int numerator, int denominator, int* n_ansp, int* d_ansp) {
	int gcd;       /* gcd between numerator and denominator         */

	/* Compute the gcd                                              */
	gcd = GCD(numerator, denominator);
	
	/* reduce the fraction by gcd                                   */
	*n_ansp = numerator / gcd;
	*d_ansp = denominator / gcd;
}

/* 
 * Get two integers
 * Return the GCD of the two integers 
 */
int GCD(int a, int b) {
	int temp;
	while (b != 0){
		temp = a % b;

		a = b;
		b = temp;
	}
	return a;
}