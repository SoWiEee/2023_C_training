#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char maze[8][8] = { { ' ', ' ', ' ', ' ', 'X', 'X', ' ', 'X'},
					{ 'X', ' ', 'X', ' ', 'X', 'X', 'X', ' '},
					{ 'X', ' ', ' ', 'X', 'X', ' ', ' ', ' '},
					{ 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X'},
					{ ' ', ' ', 'X', ' ', ' ', 'X', 'X', 'X'},
					{ 'X', ' ', ' ', ' ', 'X', 'X', ' ', ' '},
					{ 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' '},
					{ 'X', ' ', 'X', ' ', 'X', 'X', ' ', ' '} };
// initial point
int x = 1, y = 0;
// end point
int X = 7, Y = 7, find = 0;

void print_maze() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			printf("%c ", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void visit(int x, int y){
	// check (7,7)
	if (x == X && y == Y){
		find = 1;
		maze[x][y] = '*';
		print_maze();
		maze[x][y] = ' ';
		return;
	}

	// validate
	if (x >= 0 && x < 8 && y >= 0 && y < 8 && maze[x][y] == ' ') {
		maze[x][y] = '*';	// worked

		visit(x + 1, y);
		visit(x, y + 1);
		visit(x - 1, y);
		visit(x, y - 1);

		maze[x][y] = ' ';	// unworked
	}
}

int main(void) {
	visit(0, 1);
	if (find == 1) {
		printf("The path is exist\n");
	}
	else {
		printf("The path isn't exist\n");
	}

	system("pause");
	return 0;
}
