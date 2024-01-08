#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

// calculate sum from 1 to n
double sigma(int n) {
	if (n == 1) {
		return 1;
	}
	else if (n > 1) {
		return n + sigma(n - 1);
	}
}

int main(void){
	FILE* binOut, * binIn;
	int arr[4] = {3, 6, 10, 11};
	int num;
	int sum;
	int step;	// printing controller

	binOut = fopen("input.bin", "wb");
	for (int i = 0; i < 4; i++){
		fwrite(&arr[i], sizeof(int), 4, binOut);	// write int to file
	}

	fclose(binOut);

	binIn = fopen("input.bin", "rb");
	for (int i = 0; i < 4; i++){
		fread(&num, sizeof(int), 1, binIn);	// read int from file
		sum = sigma(num);

		step = 1;
		printf("%d", step);
		// print 1+2+...+number
		while(step < num){
			printf("+%d", step + 1);
			step++;
		}
		printf("=%d\n", sum);
	}

	fclose(binIn);
	system("pause");
	return 0;
}
