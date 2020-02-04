

/*program for creating ID number of user */

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int generate_of_numbers ()
{    
     int Id_User;
     int number1;
     int number2;
     int number3;
     int number4;
     int number5;
     int number6;
     srand(time(0));
     //  I had put  numbers by chance
     // function for generate ID 
     cout<< "First number: "<<1+rand()%10000<<endl;
     cin>> number1;
     cout<< "Second  number: "<<34+rand()%10000<<endl;
     cin>> number2;
     cout<< "First number: "<<1+rand()%10000<<endl;
     cin>> number3;
     cout<< "Second  number: "<<28+rand()%10000<<endl;
     cin>> number4;
     cout<< "Second  number: "<<2+rand()%10000<<endl;
     cin>> number5;
     cout<< "Second  number: "<<1+rand()%20000<<endl;
     cin>> number6;
     
     Id_User=number1*number1+number2*numer2+number3+number4*number5*number6;
     cout<<"User ID : "<<Id_User<<endl;
     return 0;
     
}




int main(int Id_User)
{
    // load function 
    int generate_of_numbers(); 
    
   return 0 ; 
}
