#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int xx;
	int yy;
	int zz;
	int mm;
	char name[20];
}address_t;

address_t scan_address(void);
void print_address(address_t data[], int total);
bool local_address(address_t data[], int front, int back);

int main()
{
	address_t data[100];
	int i;

	printf("Enter the Internet address and the computer nickname (Enter '0.0.0.0 none' to end the input) =>\n");             //prompt the user to enter the code
	for (i = 0; i < 100; i++)
	{
		data[i]=scan_address();
		if (data[i].xx == 0 && data[i].yy == 0 && data[i].zz == 0 && data[i].mm == 0 && strcmp(data[i].name, "none") == 0)
		{
			break;
		}
	}

	printf("\n\nThe data is:\n");                                                                                            //print out the data code 
	print_address(data, i);

	printf("\n");                                                                                                            //check if there is same local network
	for (int front = 0; front < i; front++)
	{
		for (int back = front + 1; back < i; back++)
		{
			if (local_address(data, front, back) == 1)
			{
				printf("\nMachines %s and %s are on the same local network.\n", data[front].name, data[back].name);
			}
		}
	}
}

address_t scan_address(void)                                                                             
{                                                                                                       //scan the data code
	address_t data;
	
		scanf("%d.%d.%d.%d", &data.xx, &data.yy, &data.zz, &data.mm);
		scanf("%s", &data.name);

	return (data);
} 

void print_address(address_t data[], int total)                                                         //print the data code
{
	for (int j = 0; j < total; j++)
	{
		printf("%d.%d.%d.%d\t%s\n", data[j].xx, data[j].yy, data[j].zz, data[j].mm, data[j].name);
	}
}

bool local_address(address_t data[], int front, int back)                                              //check if thee is the same local network
{
	if (data[front].xx == data[back].xx && data[front].yy == data[back].yy)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}