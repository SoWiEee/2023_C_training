#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


enum State {
	START = 0,
	BUILD_NUM,
	NUMBER,
	BUILD_ID,
	IDENTIFIER,
	STOP,
	FLOAT_NUM
};
State cur = START;

char buffer[100];
int index = 0;

void transition(char c) {
	if (cur == START) {	// start
		if (isdigit(c)) {
			cur = BUILD_NUM;	// 轉為 build_num
			index = 0;
			buffer[index++] = c;
		}
		else if (c == '.') {
			cur = STOP;	// 轉為 stop
		}
		else if (isalpha(c)) {
			cur = BUILD_ID;	// 轉為 build_id
			_index = 0;
			buffer[index++] = c;
		
	}
	else if (cur == BUILD_NUM) {	// build_num
		if (isdigit(c)) {
			// 狀態不變
			buffer[index++] = c;
		}
		else if (c == '.') {
			cur = FLOAT_NUM;    // 轉為 float_num
			buffer[index++] = c;
		}
		else if (c == ' ') {
			cur = NUMBER;	// 轉為 number
			buffer[index] = '\0';
			printf("%s", buffer);	// output
			printf(" - Number\n");
			cur = START;	// 轉為 start
		}
	}
	else if (cur == BUILD_ID) {	// build_id
		if (isalnum(c) || c == '_') {
			// 狀態不變
			buffer[index++] = c;
		}
		else if (c == ' ') {
			cur = IDENTIFIER;	// 轉為 identifier
			buffer[index] = '\0';
			printf("%s", buffer);	// output
			printf(" - Identifier\n");
			cur = START;	// 轉為 start
		}
	}
	else if (cur == FLOAT_NUM) {    // float_num
		if (isdigit(c)) {
			// 狀態不變
			buffer[index++] = c;
		}
		else if (c == ' ') {
			cur = NUMBER;    // 轉為 number
			buffer[index] = '\0';
			printf("%s", buffer);    // output
			printf(" - Float Number\n");
			cur = START;    // 轉為 start
		}
	}
	else if (cur == STOP) {	// stop
		// 狀態不變
	}
}

int main(void) {
	char c;
	printf("Enter a string=> ");
	while (1) {
		scanf("%c", &c);
		transition(c);
		if (c == '\n') {
			break;
		}
	}
	system("pause");
	return 0;
}
