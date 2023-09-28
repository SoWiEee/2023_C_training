#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string>

#define STRSIZ 15

typedef struct {
	int hour;					/* 0-24																	*/
	int minute;					/* 0-60																	*/
}rotation_t;

typedef struct {
	char name[STRSIZ];			/* alphabet(A-Z, a-z) and number (0-9) combinations						*/
	double diameter;			/* equatorial diameter in km (100-10000)								*/
	int moons;					/* number of moons (0-32)												*/
	int orbit_time;				/* years to orbitsun once (2-10)										*/
	rotation_t rotation_time;	/* hours(0-24) and minutes(0-60) to complete once revolution on axis	*/
}planet_t;

int scan_planet(planet_t *plnp);
void print_planet(planet_t *plnp);

int main()
{
	planet_t planet[3];			/* planet_t structure array												*/
	int index;					/* loop index															*/
	int result;					/* scan result															*/

	printf("Input 3 planets informaiton\n");
	printf("Name: alphabet(A-Z, a-z) and number(0-9) combinations is smaller 15 characters\n");
	printf("Equatorial diameter in km (100-10000)\n");
	printf("Number of moons (0-32)\n");
	printf("Years to orbitsun once (2-10)\n");
	printf("Hours(0-24) and minutes(0-60) to complete once revolution on axis\n\n");
	printf("Example:\n"
			"Name: CCR97TK\n"
			"   Equatorial diameter: 9487.943km\n"
			"   Number of moons: 3\n"
			"   Time to complete one orbit of the sun: 7 years\n"
			"   Time to complete one otation on axis: 13 hours 43 minutes\n");


	/* input 3 planets information																		*/
	for (index = 0; index < 3; index++)
	{
		printf("\nInput information of planet%d\n", index+1);
		do
		{
			/* scan planet information to array															*/
			result = scan_planet(&planet[index]);
			if (result == 1)
			{
				printf("success\n");
				/* scan success, print																	*/
				print_planet(&planet[index]);
			}
			else
			{
				printf("fail\n");
			}
		} while (result != 1);
	}
	for (index = 0; index < 3; index++)
	{
		/* print 3 planets																				*/
		print_planet(&planet[index]);
	}

	system("pause");
	return 0;
}

int scan_planet(planet_t *plnp)	/* output - address of planet_t structure to fill	*/
{
	int result;					/* scan result										*/

	/* scan planet information														*/
	result = scanf("%s%lf%d%d%d%d", plnp->name,
									&plnp->diameter,
									&plnp->moons,
									&plnp->orbit_time,
									&plnp->rotation_time.hour,
									&plnp->rotation_time.minute);

	if (result == 6)
	{
		result = 1;
	}
	else if (result != EOF)
	{
		result = 0;
	}

	/* check diameter is in range 100-10000											*/
	if (plnp->diameter < 100.0 || plnp->diameter > 10000.0)
	{
		result = 0;
		printf("Equatorial diameter is out of range\n");
	}

	/* check numbers of moons is in range 0-32										*/
	if (plnp->moons < 0 || plnp->moons > 32)
	{
		result = 0;
		printf("Number of moons is out of range\n");
	}

	/* check orbit time is in range 2-10 years										*/
	if (plnp->orbit_time < 2 || plnp->orbit_time > 10)
	{
		result = 0;
		printf("Years to orbitsun is out of range\n");
	}

	/* check hour is in 0-24														*/
	if (plnp->rotation_time.hour < 0 || plnp->rotation_time.hour > 24)
	{
		result = 0;
		printf("Hours is out of range\n");
	}
	
	/* check minute is in 0-60														*/
	if (plnp->rotation_time.minute < 0 || plnp->rotation_time.minute > 60)
	{
		result = 0;
		printf("Minutes is out of range\n");
	}

	return (result);
}

void print_planet(planet_t *plnp)	/* input - one planet structure*/
{
	/* print planet information														*/
	printf("%s\n", plnp->name);
	printf("   Equatorial diameter: %0.f km\n", plnp->diameter);
	printf("   Number of moons: %d\n", plnp->moons);
	printf("   Time to complete one orbit of the sun: %d years\n", plnp->orbit_time);
	printf("   Time to complete one otation on axis: %d hours %d minutes\n\n", plnp->rotation_time.hour, plnp->rotation_time.minute);
}
