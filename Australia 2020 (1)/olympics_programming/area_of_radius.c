#include <stdio.h>
#include <math.h>
#include <string.h>


int main(int argc, char const *argv[])
{
     
 
    const double pi = 3.141592;

    double R = 3;

    double S, L = 2 * pi *R;

    double AREA_STRUCT = 2 * 50 ;


    S=pi * R*R;
    printf("Length of radius: %f\n",R , L ); // %2 because we got  two variables
    
    printf("Area of cicle: %f\n", R ,S);
    printf("Area of cicle: %f\n", R ,S);
    printf("Area of cicle:%f\n", R ,S);
    printf("Area of cicle: %f\n", R ,S);
    printf("AREA_STRUCT: %f\n",AREA_STRUCT);


	return 0;
}