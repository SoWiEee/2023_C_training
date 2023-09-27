/*
 *The program will analysis sales about different of car's brand and different years.
 *Find sale champion and the highest annual number of car sale.
 *Final,find the highest number of car sale info within 2009~2013.
*/
#include <stdio.h>//Include library.
#include <stdlib.h>

int main() {

  int i, j;			//Loop used.
  int row = 3;			//Sale_table's row size.
  int col = 4;			//Sale_table's column size.
  int car[3][4] = {
    {210, 326, 250, 264},//BENZ
    {196, 214, 258, 396},//BMW
    {184, 276, 320, 316}//LEXUS
  };
  char car_type[3][6] = {"BENZ", "BMW", "LEXUS"};
  int year[] = {2013,2012,2010,2009};//Year
  int car_sale[3] = {0,0,0};    //Stored total sales about each brand.
  int year_sale[4] = {0,0,0,0}; //Stored total sales about annual.
  int max_sale_car = 0;         //Stored champion sale about car's brand.
  int max_sale_year = 0;        //Stored highest sales year.
  int max[2] = {0,0};           //Stored highest sales. (Year,brand,Sale number)

  //Calculated sales.
  for(i = 0; i < row; i++){
    for(j = 0; j < col; j++){
      car_sale[i] += car[i][j];
      year_sale[j] += car[i][j];
      if(car[i][j] > car[max[0]][max[1]]){
        //Find the highest number of car sale info within 2009~2013.
        max[0] = i;
        max[1] = j;
      }
    }
  }

  //Find sale champion. Than display brand and total sale.
  for(i = 0; i < row; i++){
    if(car_sale[i] > car_sale[max_sale_car])
      //Find the highest annual number of car sale. Than display year and total sale.
      max_sale_car = i;
  }
  printf("%s is champion,sale = %d.\n", car_type[max_sale_car], car_sale[max_sale_car]);

  //Find the highest annual number of car sale. Than display year and total sale.
  for(i = 0; i < col; i++){
    printf("%d's total sale = %d.\n", year[i], year_sale[i]);
    if(year_sale[i] > year_sale[max_sale_year])
      max_sale_year = i;
  }
  printf("%d is highest annual number of car sale,total sale = %d.\n", year[max_sale_year], year_sale[max_sale_year]);

  //Display the highest number of car sale info within 2009~2013.
  printf("highest number of car sale info within 2009~2013:\n");
  printf("(year,\tbrand,\tsale)\n");
  printf("(%d,\t%s,\t%d)\n", year[max[1]], car_type[max[0]], car[max[0]][max[1]]);

	system("pause");	//Please 'pause' and return
	return 0;
}
