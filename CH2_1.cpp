#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>              /*printf, scanf definitions*/
#include<stdlib.h>              /*system definition*/

#define _FARE_PER_MILE 1.5      /*_FARE_PER_MILE belongs to the number "1.5" */
int 
main(void)
{    
    /*define the words you called,
      between the words should not use a "Space" but a "_" */
    double begin_miles,        /*when the miles begin to count          */
           end_miles,          /*when tie miles end to coumt            */
           between_miles,      /*the miles between he begin and the end */
           fare;               /*how much to pay for the passed miles   */

    printf("TAXI FARE CALCULATOR\n");                  /*write the words down*/                       /*the "\n" means switch lines */
    printf("Enter beginning odometer reading=>");
    scanf("%lf", &begin_miles);                       /*to type how much miles in the beginning*/
    printf("Enter ending odometer reading=>");
    scanf("%lf", &end_miles);                         /*to type how much miles in the end*/
       
    between_miles= end_miles - begin_miles;           /*to minus from the endng distance to the beginning distance*/
    fare = _FARE_PER_MILE * between_miles;            /*to sum up the total fare of the distance*/
    printf("You traveled a distance of %.2f miles.",between_miles);     /*the "between_miles" behind the "," belongs to the "%.2f" in the front*/
    printf("At $%.2f per mile,\n", _FARE_PER_MILE);                     /*and the number of the "%.2f" remains on what definition it types behind the "," */
    printf("your fare is $%.2f", fare);
   
    system("PAUSE");
    return (0);         

}
     
    


