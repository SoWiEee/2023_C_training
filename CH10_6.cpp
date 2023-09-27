#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char language[20];
	int numbers;
	char MAX_WORDS[20][20];
}list;

list load_word_list(FILE* language, list file_list);
list add_word(list file_list,char add_words[20]);
bool contains(list file_list, char word[20]);
bool equal_lists(list front, list back);
void display_word_list(list file_list);


int main()
{
	FILE* English, * Japanese, * Spanish, * copy;                   //open the file
	English = fopen("English.txt", "r");
	Japanese = fopen("Japanese.txt", "r");
	Spanish = fopen("Spanish.txt", "r");
	copy = fopen("copy.txt", "r");

	list file_list [4];
	file_list[0] = load_word_list(English, file_list[0]);           //load word list
	file_list[1] = load_word_list(Japanese, file_list[1]);
	file_list[2] = load_word_list(Spanish, file_list[2]);
	file_list[3] = load_word_list(copy, file_list[3]);


    char  add_language[20], add_words[20];
	printf("Emter which language you are going to enter and 12 words to add into the list(¡¹English, Japanese, Spanish only¡¹)=>\n");
	scanf("%s", &add_language);
	for (int i = 0; i < 12; i++)                                  //enter the language yoe wamt to copy the words in and copy the words
	{
		scanf("%s", &add_words);
		if (strcmp(add_language, "English") == 0 || strcmp(add_language, "english") == 0)
		{
			file_list[0] = add_word(file_list[0], add_words);
		}
		else if (strcmp(add_language, "Japanese") == 0 || strcmp(add_language, "japanese") == 0)
		{
			file_list[1] = add_word(file_list[1], add_words);
		}
		else if (strcmp(add_language, "Spanish") == 0 || strcmp(add_language, "spanish") == 0)
		{
			file_list[2] = add_word(file_list[2], add_words);
		}

	}
	

	char search_word[20];
	printf("\n\nEnter the word you want to find whether it is in any list=>");         //find if the word you enter is in any list
	scanf("%s", &search_word);
	if (contains(file_list[0], search_word) == 1)
	{
		printf("\n\n¡° The word %s is in the 1 list, the language of the list is %s.\n", search_word, file_list[0].language);
	}
	else
	{
		printf("\n\nThe word %s is NOT in the 1 list, the language of the list is %s.\n", search_word, file_list[0].language);
	}
	if (contains(file_list[1], search_word) == 1)
	{
		printf("¡° The word %s is in the 2 list, the language of the list is %s.\n", search_word, file_list[1].language);
	}
	else
	{
		printf("The word %s is NOT in the 2 list, the language of the list is %s.\n", search_word, file_list[1].language);
	}
	if (contains(file_list[2], search_word) == 1)
	{
		printf("¡° The word %s is in the 3 list, the language of the list is %s.\n", search_word, file_list[2].language);
	}
	else
	{
		printf("The word %s is NOT in the 3 list, the language of the list is %s.\n", search_word, file_list[2].language);
	}
	if (contains(file_list[3], search_word) == 1)
	{
		printf("¡° The word %s is in the 4 list, the language of the list is %s.\n", search_word, file_list[3].language);
	}
	else
	{
		printf("The word %s is NOT in the 4 list, the language of the list is %s.\n", search_word, file_list[3].language);
	}

	printf("\n\n");
	for (int i = 0; i < 3; i++)                                                           //check is there is any list the same
	{
		for (int j = i+1; j < 4; j++)
		{
			if (equal_lists(file_list[i], file_list[j]) == 1)
			{
				printf("¡° The %d list and the %d list is the same.\n", i+1, j+1);
			}
			else
			{
				printf("The %d list and the %d list is NOT the same.\n", i+1, j+1);
			}
		}
	}


	printf("\n\n");                                                           //print out the list
	for (int i = 0; i < 4; i++)
	{
		printf("\nList %d:\n", i+1);
		display_word_list(file_list[i]);
		printf("\n\n");
	}


	fclose(English);                                                          //close the file
	fclose(Japanese);
	fclose(Spanish);


	system("PAUSE");
	return(0);
}

list load_word_list(FILE* language,list file_list)                           //load the word from the file into the list
{
	int scan;
	char word[20];
	fscanf(language, "%s", &file_list.language);
	file_list.numbers = 0;
	scan= fscanf(language, "%s", &word);
	while (scan==1)
	{
		file_list = add_word(file_list, word);
		scan=fscanf(language, "%s", &word);
	}
	return(file_list);
}

list add_word(list file_list, char add_words[20])                            //add words into the list
{
	if (file_list.numbers < 20)
	{
		if (!contains(file_list, add_words))
		{
			file_list.numbers++;
			strcpy(file_list.MAX_WORDS[file_list.numbers-1], add_words );
		}
	}
	else
	{
		printf("List full, %s not added.\n", add_words);
	}
	return(file_list);
}

bool contains(list file_list, char word[20])                                 //check if there is the same word in the list
{
	for (int i = 0; i < file_list.numbers; i++)
	{
		if (strcmp(file_list.MAX_WORDS[i], word) == 0)
		{
			return(1);
		}
	}
	return(0);
}

bool equal_lists(list front, list back)                                     //check if there is the same list
{
	if (strcmp(front.language , back.language )==0 && front.numbers == back.numbers)
	{
		for (int i = 0; i < back.numbers; i++)
			{
				if (!contains(front,back.MAX_WORDS[i]))
				{
					return(0);
				}
			}
		return(1);
	}
	else
	{
		return(0);
	}
}

void display_word_list(list file_list)                                      //print out the list
{
	printf("%s\n", file_list.language);
	printf("There is %d words in the list.\n", file_list.numbers);
	printf("=>\n");
	for (int i = 0; i < file_list.numbers; i++)
	{
		printf("%s\t", file_list.MAX_WORDS[i]);
		if ((i+1)%4==0)
		{
			printf("\n");
		}
	}
}