/* 
Document Base created with purpose : to give opportunity to create convenient
way using base date 
each window in program 
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
  
  int get_the_role_of_user()
  {
    cout<<"role:";
    cin>>role_of_the_user;
    return 0;  
  }

  // get salary 
  double get_salary_with_help_of_index ( double results_of_salary)
  {
     results_of_salary  =  salary_of_the_user;
     return salary_of_the_user;
    
  }   

// functions of calculating 
private :
   // calculate salary of user 

   double calculate_salary(  ) 
   {
      double results_of_salary;
      int index; 
      int earned_per_mounth;
     // each position  has index ,  than upper position than upper index .

      cout<<"Enter of the index :"<<endl;
      cin>>index;
      // How much  employe has earned 
      cout<< "How much employe has earned ? ";
      cin>> earned_per_mounth;

      results_of_salary = earned_per_mounth * index;  
       
     return results_of_salary;
   } 

};
int main ()
{
  // Our results in the table
  // functions for main window  


 // function  to create user in table ;
 int create_user() 
 {
    User employe;
  employe.get_name_of_the_user();
  employe.get_second_name_of_the_user();
  employe.get_age_of_the_user();
  employe.get_gender_of_the_user();
  employe.get_salary_with_help_of_index();
  employe.get_the_role_of_user();


   return 0;
 }  
 
 
  return 0;
}