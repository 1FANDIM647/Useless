/* 
Document Base created with purpose : to give opportunity to create convenient
way using base date 
GPL 2.0 
Developed by Blessed Home 
2020
*/

#include <iostream>
#include <string>
#include <math>
#include <thread>
#include <memory>


using namespace std; 

// class for creating methods and datas of user in the table 
class User 
{

public:    
 // user's data  
 
 string name; 
 
 string second_name ;
 // gender of user 
 string gender;
 
 int  age_of_the_user;
 
 string role_of_the_user;
  
 double salary_of_the_user; 

// name of user 
 int get_name_of_the_user ()
  {
    cout<<"Enter name: ";
    cin>>name;
    return 0;
  }

  int get_second_name_of_the_user()
  {
    cout<<" second_name: ";
    cin>> second_name;
    return 0;
  }  
// gender of the user 
  int get_gender_of_the_user()
  {
    cout<<"gender";
    cin>>gender;
    return 0;
  }
 // get age of the user  
  int  get_age_of_the_user()
  { 
    cout<<"Enter age: ";
    cin>>age_of_the_user;
    if ( age_of_the_user >= 450 )
    {
      cout<<"impossible age"<endl;
    }
    return age_of_the_user;
  } 


// functions of calculating 
private :

};
int main ()
{
  // Our results in the table
  return 0;
}