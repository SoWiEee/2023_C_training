#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int within_x_percent(int, int, int);

int main()
{
	int data;

	printf("Enter the data of substance: ");
	scanf("%d", &data);

	if (within_x_percent(100, data, 5))
		printf("The substance is water.");
	else if (within_x_percent(357, data, 5))
		printf("The substance is Mercury.");
	else if (within_x_percent(1187, data, 5))
		printf("The substance is Copper.");
	else if (within_x_percent(2193, data, 5))
		printf("The substance is Silver.");
	else if (within_x_percent(2660, data, 5))
		printf("The substance is Gold.");
	else
		printf("Substance unknown!");

	system("PAUSE");
	return 0;
}

int within_x_percent(int ref, int data, int x)
{
	if (data - ref >= 0)//data>ref
	{
		if (ref*x / 100 >= data - ref)//if data - ref is in the range
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else//data<ref
	{
		if (ref*x / 100 >= ref - data)//if ref - data is in the range
		{
			return 1;
		}
		else
		{
			return 0;
		}

	}
	return 0;
}


