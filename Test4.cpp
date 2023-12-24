#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


int blob_check(int pixels[5][5], int x, int y) {
    // x,y is empty or out of grid => return 0
    // x,y is filled => return 1 + blob sizes
    // cover counted block to 0
    int count = 1;
    if (x > 4 || x < 0 || y > 4 || y < 0) {
        return 0;
    }
    else {
        if (pixels[x][y] == 0) {
            return 0;
        }
        else {
            pixels[x][y] = 0;   // count = 1
            for (int i = -1; i <= 1; i++){
                for (int j = -1; j <= 1; j++){
                    count += blob_check(pixels, x + i, y + j);
                }
            }
            return count;
        }
    }

}


int main(void) {
	// blob : 連續相鄰的 pixel = 1 的區域
	int pixels[5][5] = { {1,1,0,0,0},
						{0,1,1,0,0},
						{0,0,1,0,1},
						{1,0,0,0,1},
						{0,1,0,1,1} };
    int x, y, temp;

	// display table
    printf("y\n");
    for (int i = 0; i < 5; i++){
        printf("%d", 4 - i);
        for (int j = 0; j < 5; j++){
            if (pixels[i][j] == 1){
                printf("(1)");
            }
            else{
                printf("(0)");
            }
        }
        printf("\n");
    }
    for (int i = 0; i < 5; i++){
        printf("%3d", i);
    }
    printf(" x\n\n");

    // get (x,y)
    printf("Enter the (x , y) you want to count of the pixels belongings =>");
    scanf("%d, %d", &x, &y);

    // transform to array coordinates
    temp = x;
    x = y;
    y = temp;
    x = 4 - x;

    // output result
    printf("The count of the pixels belongings is %d.\n", blob_check(pixels, x, y));

	system("pause");
	return 0;
}


