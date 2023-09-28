/*
 * takes an input file ("BATTING.IN") containing player numbers and batting records
 * compute each player's batting average in input file
 * finally, output each player's number, batting record, and his batting average to the output file "BATTING.OUT"
 */

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void initBatRecord(int[]);
void addBatRecord(int[], char);
double batting_average(int[]);

int main(void) {
	FILE *inp;   /* pointer to input file                 */
	FILE *outp;  /* pointer to output file                */
	char item;
	bool number_mode = false;
	bool char_mode = false;
	int bat_record[5];/* batting record statistic array
					     0 : H
						 1 : O
						 2 : W
						 3 : S
						 4 : P                            */
	int input_status; /* status value returned by fscanf  */

	/* initial the statistic array                        */
	initBatRecord(bat_record);

	/* Prepare file for input or output                   */
	inp = fopen("BATTING.IN", "r");
	outp = fopen("BATTING.OUT", "w");

	input_status = fscanf(inp, "%c", &item);
	while (input_status == 1) {   // loop until EOF
		switch (item) {
		case '\n':
			fprintf(outp, "\nbatting average = %lf\n", batting_average(bat_record));
			printf(" \nbatting average = %lf\n", batting_average(bat_record));
			initBatRecord(bat_record);
			break;
		case 'H':
		case 'O':
		case 'W':
		case 'S':
		case 'P':
			if (!char_mode) {
				number_mode = false;
				char_mode = true;
				printf("\nplayer's batting record: ");
				fprintf(outp, "\nplayer's batting record: ");
			}
			printf("%c", item);
			fprintf(outp, "%c", item);
			addBatRecord(bat_record, item);
			break;
		default:
			if (!number_mode) {
				number_mode = true;
				char_mode = false;
				printf("\nplayer's number: ");
				fprintf(outp, "\nplayer's number: ");
			}
			printf("%c", item);
			fprintf(outp, "%c", item);
		}
		input_status = fscanf(inp, "%c", &item);
	}

	fclose(inp);
	fclose(outp);

	system("PAUSE");
	return 0;
}

/*
 * Get one integer pointer 
 * Returns the initialed array
 */
void initBatRecord(int arr[]) {
	int i;
	for (i = 0; i < 5; i++) {
		arr[i] = 0;
	}
}

/*
 * Get the batting record statistic array
 * return the batting average
 */
double batting_average(int arr[]) {
	return (double)arr[0] / (arr[0] + arr[1]);
}

/*
 * add a batting record into statistic array
 */
void addBatRecord(int arr[], char item) {
	/*  batting record statistic array
	 *  0 : H
	 *  1 : O
	 *  2 : W
	 *  3 : S
	 *  4 : P                            */
	switch (item) {
	case 'H':
		arr[0]++;
		break;
	case 'O':
		arr[1]++;
		break;
	case 'W':
		arr[2]++;
		break;
	case 'S':
		arr[3]++;
		break;
	case 'P':
		arr[4]++;
		break;
	default: // do nothing
		break;
	}
}