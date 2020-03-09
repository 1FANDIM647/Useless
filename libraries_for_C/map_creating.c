/*
MAP of DU  engine 1.0 
Blessed soft company 2020
*/
#include <graphics.h> 
#include "module_phs.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <conio.h>

void MAP_CREATION ()
{ 
    // function draws the line 
long int position_line (int X0 , int Y0)

  {   // pointers for drawing of line
      int  *point1;
      int  *point2;
      
      point1 =&X0;
      point2 =&Y0;
      
      while (point1 != point2 )
      {
         long int draw_line();
      }
      
      // in case you want to create a point 


      return 0;
  }
// function  of map
long int  MAP ()
{  // create cordianats 
  // create system of cordiants
  int create_2d_map (int x_left ,int y_up ,int x_right , int y_down)
   {  // direction of line
       char direction;

        scanf("%d", "Enter X line LEFT", x_left);
        scanf ("%d", "Enter Y line DOWN", y_down);
        scanf("%d", "Enter X line RIGHT", x_left);
        scanf ("%d", "Enter Y line UP", y_down);
       return x , y ;
       // this function draws at special territory 
        draw2D( x_left ,y_up,x_right,y_down );
   }   
   
} }


 
int area_of_figure () 
{   

   /*computer chooses position of figure  */
   int random_position () 
   {
     // because in  square ecuation  we use  a , b ,c
     int a_for_random_area = rand()%200;
     
     int b_for_random_area = rand()%200;

     int c_for_random_area = rand()%100;
     
     int square_ecuation_for_random_values ( int a_for_random_area , int b_for_random_area , int c_for_random_area)
     {
         D = (b_for_random_area*b_for_random_area)-4*a_for_random_area*c_for_random_area;

          if (D>0)
           {
           X1=(-b_for_random_area+sqrt(D))/(2*a_for_random_area);
           X2=(-b_for_random_area-sqrt(D))/(2*a_for_random_area);
              float position_of_figure = draw2D("x1=%f",X1 , X2); 
           }
           if (D<0)
           { // recursion
             square_ecuation_for_random_values();
           }
           if (D==0)
            {
              X1=(-b_for_random_area+sqrt(D))/(2*a);
              draw2D("x1=x2=%f", x1);
            }

         return position_of_figure;   
     }
     
   }
 
 int  value_of_figure () 
 
 {
   // we can  get number (value)
   
   float  val_of_figure = sizeof(float position_of_figure );
   print("%f", "Value of figure in  memory :",position_of_figure);  // output   
  

 } 

}


int main ()
{   
  // load  function  for  creating  of map 
  void MAP_CREATION ();

    return 0 ;
}