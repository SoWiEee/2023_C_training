#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

/*
enum State {
	START = 1,
	IDENTIFIER,
	NUMBER,
	BUILD_ID,
	BUILD_NUM,
	STOP
}state;
*/

char buffer[100];
int buffer_index = 0;

void transition(char c, int* ptr) {
	if (*ptr == 0) {	// start
		if (isdigit(c)) {
			*ptr = 1;	// 轉為 build_num
			buffer_index = 0;
			buffer[buffer_index++] = c;
		}
		else if (c == '.') {
			*ptr = 5;	// 轉為 stop
		}
		else if (isalpha(c)) {
			*ptr = 3;	// 轉為 build_id
			buffer_index = 0;
			buffer[buffer_index++] = c;
		}
	}
	else if (*ptr == 1) {	// build_num
		if (isdigit(c)) {
			// 狀態不變
			buffer[buffer_index++] = c;
		}
		else if (c == ' ') {
			*ptr = 2;	// 轉為 number
			buffer[buffer_index] = '\0';
			printf("%s", buffer);	// output
			printf(" - Number\n");
			*ptr = 0;	// 轉為 start
		}
	}
	else if (*ptr == 3) {	// build_id
		if (isalpha(c) || isdigit(c) || c == '_') {
			// 狀態不變
			buffer[buffer_index++] = c;
		}
		else if (c == ' ') {
			*ptr = 4;	// 轉為 identifier
			buffer[buffer_index] = '\0';
			printf("%s", buffer);	// output
			printf(" - Identifier\n");
			*ptr = 0;	// 轉為 start
		}
	}
	else if (*ptr == 5) {	// stop
		// 狀態不變
	}
}

int main(void) {
	char c;
	int state = 0;
	int* ptr = &state;
	while (1) {
		scanf("%c", &c);
		transition(c, ptr);
		if (c == '\n') {
			break;
		}
	}
	system("pause");
	return 0;
}
