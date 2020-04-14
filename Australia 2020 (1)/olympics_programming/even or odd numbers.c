#include <stdlib.h>
#include <stdio.h>

int main()
{   
	int number;
    printf("Enter:");
    scanf("%d",&number);

    if (number%2 == 0)
    {
    	printf("Even number ");
    }
    else
    {
    	printf("Odd number" );
    }
  
      

    printf("%d\n",number );
	return 0;
}