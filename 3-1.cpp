#include<stdio.h>
#include<stdlib.h>

int main()
{
    int principal, downPay, yearRate, total;
    float monthRate;
    printf("Enter purchase price: ");
    scanf_s("%d", &principal);
    printf("Enter downPayment: ");
    scanf_s("%d", &downPay);
    printf("Enter annual interest rate: ");
    scanf_s("%d", &yearRate);
    printf("Enter number of payments");
    scanf_s("%d", &total);

    printf("You monthly payment will be payment");

    system("pause");
    return 0;
}
