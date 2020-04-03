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

 long int ID_code_of_the_User;

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

// he has control in Data base 
class Administrator : User public 
{

public:

    string  name; 

private:    
    // give a role to user , "employe it is object of class  "
    string give_role (employe , string role_of_the_user)
    {  
       string role_for_the_current_user;

        cout<<" What is the role of this user:";
        cin>>role_for_the_current_user;
        
       role_of_the_user = role_for_the_current_user;

       return role_of_the_user;
    }
    
    int delete_role(employe)
    {
      delete( employe.get_the_role_of_user);
      
      return0;
    }

};


//Data Base can contains package with documents in defined folder 

class Package 
{
  public:


 private:

};

int main ()
{
  // Our results in the table
  // functions for main window  


 // function  to create user in table ;
 long int button_create_user() 
 {
  
  // method of geeting  salary 
  // index , constable  salary and so on .
  
   int salary;
   // choose method  
  switch (salary)
  { 
    case 1:
      get_salary_with_help_of_index();
      int salary_method = get_salary_with_help_of_index();
    break;
    case 2:
      constable_salary();
      int salary_method = constable_salary();
    break;
    case 3:
      any_salary();
      int salary_method = any_salary();
    break    
    default:
    cout<<" Method doesn't exist "<<endl; 
   break;
  } 

   User employe;
  employe.get_name_of_the_user();
  employe.get_second_name_of_the_user();
  employe.get_age_of_the_user();
  employe.get_gender_of_the_user();
  employe.get_the_role_of_user();
  employe.salary_method;

  // condition  to eaqual names , user may not  to have equal name and second name 
  if ( name == second_name )
  {
    cout<<"impossible "<<endl;
  }   
  // return user
   return employe;
 }  
 
 
  return 0;
}