// Numbers of Fibonachi

#include <stdio.h>
#include <stdlib.h>

int main ()
{
  
  int number ;
  
  printf("Enter a number for the task:");

  scanf("%d",&number);


  int a , b = 1;

  int k = 3;

  while (k <=number)
  {
    b=a+b;
    a=b-a;
    k++;
  }
  
  printf("Fibonachi number: %d\n",b );

  return 0;
}