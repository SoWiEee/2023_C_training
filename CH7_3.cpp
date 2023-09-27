#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void fget_point_mass(int x[],int y[],int z[],int mass[],int n,FILE* in);                             /*void the function that scan he data from the input file*/
void center_grav(int x[], int y[], int z[], int mass[], int n, double gravity[]);					 /*void the function that calculate the center of the gravity*/
void fwrite_point_mass(int x[], int y[], int z[], int mass[], int n, FILE* out, double gravity[]);   /*void the function that output the result to the out put file*/

int main()
{
	FILE* in;                                           /*define the input file*/
	FILE* out;                                          /*define the output file*/
	in = fopen("input.txt", "r");                       /*open the input file and needs to read the data in it*/
	out = fopen("output.txt", "w");                     /*open the output file and needs to write data on it*/
 
	int x[10],y[10],z[10], mass[10], n;                 /*the (x,y,z) and the mass of the point in the input file, 'n' belongs to how much point in the data*/
	double gravity[3];                                  /*the result which is the center of the gravity*/

	fscanf(in, "%d", &n);                               /*scan the 'n' from the input file*/
	fget_point_mass(x, y, z, mass, n, in);              /*call the function to scan the data*/
	center_grav(x, y, z, mass, n, gravity);             /*call the function to calculate the center of the gravity*/
	fwrite_point_mass(x, y, z, mass, n, out, gravity);  /*call the function to output the result*/

	fclose (in);                                        /*close the input file*/
	fclose(out);                                        /*close the output file*/

	system("PAUSE");
	return(0);
}
void fget_point_mass(int x[], int y[], int z[], int mass[], int n, FILE* in)
{
	for (int i = 0; i < n; i++)                        /*do the loop to scan the data for 'n' times*/
	{
		fscanf(in, "%d", &x[i]);                       /*scan the 'x' of the point in the data*/
		fscanf(in, "%d", &y[i]);                       /*scan the 'y' of the point in the data*/
		fscanf(in, "%d", &z[i]);                       /*scan the 'z' of the point in the data*/
		fscanf(in, "%d", &mass[i]);                    /*scan the mass of the point in the data*/
	}
}
void center_grav(int x[], int y[], int z[], int mass[], int n, double gravity[])
{
	double gx = 0, gy = 0, gz = 0,m=0;                 /*the (x,y,z) of each point times to the mass of each point and sum up, 'm' belongs to the sum of every point's mass*/
	for (int i = 0; i < n; i++)                        /*do the loop to sum up each 'point times mass' for 'n' times*/
	{
		gx += x[i] * mass[i];                          /*each 'x' of the point times to the point's mass*/
		gy += y[i] * mass[i];                          /*each 'y' of the point times to the point's mass*/
		gz += z[i] * mass[i];                          /*each 'z' of the point times to the point's mass*/
		m += mass[i];
	}
	gravity[0] = gx / m;                               /*calculate the 'x' that belongs to the center of the gravity*/
	gravity[1] = gy / m;                               /*calculate the 'y' that belongs to the center of the gravity*/
	gravity[2] = gz / m;                               /*calculate the 'z' that belongs to the center of the gravity*/
}
void fwrite_point_mass(int x[], int y[], int z[], int mass[], int n, FILE* out, double gravity[])
{
	fprintf(out, "location:\n");                       /*print out the label title 'location'*/
	for (int i = 0; i < n; i++)                        /*do the loop to print the data on the output file for 'n' times*/
	{
		fprintf(out, "\t\t%2d \t",x[i]);               /*print the 'x' of the data point*/
		fprintf(out, "\t\t%2d \t",y[i]);               /*print the 'y' of the data point*/
		fprintf(out, "\t\t%2d \t\n",z[i]);             /*print the 'z' of the data point*/
	}

	fprintf(out, "\nmass:\n");                         /*print out the label title 'mass'*/
	for (int i = 0; i < n; i++)                        /*do the loop to print the data on the output file for 'n' times*/
	{
		fprintf(out, "\t\t%d\n", mass[i]);             /*print the mass of each point*/
	}

	fprintf(out, "\nn: \t\t%d\n\n",n);                 /*print the lable title 'n' and the data 'n' on the output file*/

	fprintf(out, "The center of the gravity is : ");   /*print out the result of the center of the gravity on the output file*/
	fprintf(out, "( %.2f , %.2f , %.2f )", gravity[0], gravity[1], gravity[2]);
}