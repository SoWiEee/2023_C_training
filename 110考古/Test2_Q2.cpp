/*
 * Compute and display the no. of employee, their names, salary, bonus, tax rate, paid tax, net salary.
 */
 
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void Comp_Salary(int, int, char, double*, double*);
void clearBuffer();

int main()
{
	int  number_e;		/* input - the number of employees 			   */
	char name; 			/* input - the intial name for each employee   */
	char gender;		/* input - the gender for each employee		   */
	int  work_hour;		/* input - the working hours for each employee */
	int  hour_pay;		/* input - the hour pay for each employee 	   */
	double netSalary;	/* output - sign of value					   */
	double paidTax;		/* output - sign of value					   */	
	int i;				

	/* Enter the number of employees */
	printf("Enter the number of employees: ");
	scanf("%d", &number_e);
	
	while(number_e <= 0)
	{
        clearBuffer(); 
          
		printf("Error! Enter the number of employees: ");
		scanf("%d", &number_e);
	}

	for(i = 0; i < number_e; i++)
	{        
		work_hour = 0;  
        hour_pay = 0;
		
        clearBuffer();
        
		/* Enter the intial name */
        printf("Enter the intial name: ");
		scanf(" %c", &name);
		
		clearBuffer();
		
		/* Enter the gender */
		printf("Enter the gender (m or f): "); 		
		scanf(" %c", &gender);
		
        while(gender != 'm' && gender != 'f')
        { 
            clearBuffer();  
                   
    		printf("Error! Enter the gender (m or f): ");
			scanf(" %c", &gender); 
        }
		
		/* Enter the working hours */
		printf("Enter the working hours: "); 
		scanf(" %d", &work_hour);
		
		/* 0 < working hours <= 80 */
		while(work_hour <= 0 || work_hour > 80)
        { 
            clearBuffer();
            
    		printf("Error! Enter the working hours: ");
    		scanf(" %d", &work_hour); 
		}
		
		/* Enter the hour pay */
		printf("Enter the hour pay: "); 
		scanf(" %d", &hour_pay);
		
		/* 0 < hour pay */
		while(hour_pay <= 0)
        { 
            clearBuffer();
            
    		printf("Error! Enter the hour pay: ");
    		scanf(" %d", &hour_pay); 
		}
		
		/* Display the no. of employee, their names, salary, bonus, tax rate, paid tax, net salary */
		printf("\nNo.%d employee:\n", i + 1);
        printf("Name: %c\n", name);

        Comp_Salary(work_hour, hour_pay, gender, &netSalary, &paidTax);
        
        printf("Paid tax: %.0lf\n", paidTax); 
        printf("Net salary: %.0lf\n\n", netSalary);       
	}

	system("PAUSE");
	return 0;
}

void clearBuffer()
{
	char discard = ' ';
	
	do
			{
				scanf("%c", &discard);
			} while (discard != '\n');
}

/* Compute the salary */
void Comp_Salary(int work_hour, int hour_pay, char gender, double *netSalary, double *paidTax)
{	
    int salary = 0;
    
    if(40 <= work_hour && work_hour < 60)
	{
		salary =  2 * work_hour * hour_pay;
		printf("Salary: %d\n", salary);
	}
	else if(work_hour >= 60)
	{
		salary =  3 * work_hour * hour_pay;
		printf("Salary: %d\n", salary);
	}
	else
	{
		salary = work_hour * hour_pay;
		printf("Salary: %d\n", salary);
	}

	switch(gender)
	{
        case 'M':
		case 'm':
		
		    printf("Bonus: 100\n");
			printf("Tax rate: 8%\n");
            			
			*netSalary = salary * (1 - 0.08) + 100;
            *paidTax = salary * 0.08;	
			
			break;
			
		case 'F':
		case 'f':
		
            printf("Bonus: 200\n");
			printf("Tax rate: 6%\n");
			
			*netSalary = (double)salary * (1 - 0.06) + 200;			
			*paidTax = salary * 0.06;
			
			break;
			
		default:
		
			break;
	}
}
