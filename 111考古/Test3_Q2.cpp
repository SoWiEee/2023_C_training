/*
 *First,read text file into programa and use string array to stored text.
 *Than use "Selection_Sorting" fnuction to sort string array in alphabetical order.
 *Final write a file to save result.
*/
#define _CRT_SECURE_NO_WARNINGS	//Use 'scanf' function
#include <stdio.h>//Include library.
#include <stdlib.h>
#include <string.h>

void Selection_Sorting(char *word[], int size);//Sort string array in alphabetical order.

int main() {

  FILE *Girls_input_file = fopen("Girls.txt", "r");//Read "Girls.txt".
  FILE *Girls_output_file = fopen("Girls_sorted.txt", "w");//Write "Girls_sorted.txt".
  char girl_names[100][20];     //Stored girl's names from "Girls.txt".
  char *girl_names_pointer[100];//Stored 'girl_names' pointer.
  int size = 100;               //Number of names.

  if(!Girls_input_file){
    //File open failed.
    printf("Error! File open failed.\n");
    return 1;
  }

  //Read girl's names from "Girls.txt",then stored girl's names and pointer.
  printf("-----ORIGINAL-----\n");
  for(int i = 0; i < size; i++){
    fgets(girl_names[i], 20, Girls_input_file);
    girl_names_pointer[i] = girl_names[i];
    printf("%s", girl_names_pointer[i]);
  }

  //Sort string array in alphabetical order.
  Selection_Sorting(girl_names_pointer, size);

  //Write to sorted string array,and display.
  printf("-----SORTED-----\n");
  for(int i = 0; i < size; i++){
    fputs(girl_names_pointer[i], Girls_output_file);
    printf("%s", girl_names_pointer[i]);
  }

  fclose(Girls_input_file);//Close file.
  fclose(Girls_output_file);

  system("pause");	//Please 'pause' and return
	return 0;
}

void Selection_Sorting(char *word[], int size) {
  //Sort string array in alphabetical order.
  char *swap;//Stored pointer.
  for (int i = 0; i < size; i++) {
		for (int j = i+1; j < size; j++) {
			if (strcmp(word[i],word[j]) > 0) {
        //word[i] > word[j]
        swap = word[i];
        word[i] = word[j];
        word[j] = swap;
			}
		}
	}
}
