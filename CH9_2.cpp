#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(char pharse[],int start,int end)           //run the funtion to check if the pharse is palindrome
{
	if (start <= end)
	{
		if (pharse[start] != pharse[end])
		{
			return(0);
		}
		else
		{
			return(compare(pharse, start + 1, end - 1));
		}
	}
	else
	{
		return(1);
	}
}
int main()
{
	char pharse[50];

	printf("Enter the pharse =>");                                                                                    //prompt the user to enter the pharse he or she wants to check
	scanf("%s", &pharse);                                                                                             //scan the pharse
    printf("\nIsn't the pharse a palindrome? (yes=1,no=0) => %d\n", compare(pharse, 0, strlen(pharse)-1));            //output the result

	system("PAUSE");
	return(0);
}