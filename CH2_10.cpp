#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>    /*printf, scanf definitions*/
#include<stdlib.h>   /*system definition*/

int
main(void)
{
	double x1,       /*the "x"of the first (x,y) you gave*/
		   y1,       /*the "y"of the first (x,y) you gave*/
		   x2,       /*the "x"of the second (x,y) you gave*/
		   y2,       /*the "y"of the second (x,y) you gave*/
		   x3,       /*the "x"of the (x,y) after average of the first and the second point*/
		   y3,       /*the "y"of the (x,y) after average of the first and the second point*/
		   m1,       /*the slope of the line connected by the first and the second point */
		   m2,       /*the slope of the perpendicular bisector*/
		   b;        /*the "b" of the "y=ax+b"*/
	 
	printf("Enter a point=>");           /*enter the first point*/
	scanf("%lf%lf", &x1, &y1);
	printf("Enter another point=>");     /*enter the second point*/
	scanf("%lf%lf", &x2, &y2);

	x3 = (x1 + x2) / 2;
	y3 = (y1 + y2) / 2;                  /*compute the middle point of the first and the second*/

	m1 = (y2-y1) / (x2-x1);              /*compute the slope of the line connected by the first and the second point*/
	m2 = -1 / m1;                        /*compute the slope of the perpendicular bisector*/
	b = y3 - m2 * x3;                    /*compute the "b" of the "y=ax+b"*/

	printf("y=%gx+%g", m2, b);

	system("PAUSE");
	return (0);
}