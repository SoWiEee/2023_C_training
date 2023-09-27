#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double within_x_percent(double ref,double data,double x);     /*define a function*/
                                                              /*ref=>the normal boiling point of the expected substance*/
int
main(void)
{
	double data,   /*the observed boiling point of a substance*/
		x;         /*within how much percent higher or lower of the expected boiling point*/
	

	x = 5;         /*according to the telling ,the data must within 5% higher or lower*/
	
	
	printf("Enter the observed boiling point of the substance in ¢J =>");    /*enter the observed boiling point of a substance*/
	scanf("%lf", &data);


	/*give conditions and output the result of the substance*/
	if ( within_x_percent(100, data, x) == true)
 {
	printf("The substance is => Water\n");
 }
else if (within_x_percent(357, data, x) == true)
 {
	printf("The substance is => Mercury\n");
 }
else if (within_x_percent(1187, data, x) == true)
 { 
	printf("The substance is => Copper\n");
 } 
else if ( within_x_percent(2193, data, x) == true)
 {
	printf("The substance is => Silver\n");
 }
else if (within_x_percent(2660, data, x) == true)
 {
	printf("The substance is => Gold\n");
 }
else
 {
	printf("Substance unknown\n");
 }

	system("PAUSE");
	return(0);
}

double within_x_percent(double ref, double data, double x)   
{
	double plus_x_percent,    /*x% higher*/
		minus_x_percent;      /*x% lower*/

	/*calculate the value of the range that is between "plus_x_percent" and "minus_x_percent"*/
	plus_x_percent = ref + ref * (x / 100);        
	minus_x_percent = ref - ref * (x / 100);
	

	/*if the data is within the range => return "true"
	                           if not => return "false"*/
	if(data<=plus_x_percent && data>=minus_x_percent)
	{
		return(1);
	}
	else
	{
		return(0);
	}
	
}
