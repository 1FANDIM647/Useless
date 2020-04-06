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
#include <fstream>

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
    string give_role (employee , string role_of_the_user)
    {  
       string role_for_the_current_user;

        cout<<" What is the role of this user:";
        cin>>role_for_the_current_user;
        
       role_of_the_user = role_for_the_current_user;

       return role_of_the_user;
    }
    
    int delete_role(employee)
    {
      delete( employee.get_the_role_of_user);
      
      return0;
    }
  
    // 
    void send_package()
    {
       void get_address();
       
       int IP_CODE = get_address_ip_user();
 
    }

};


//Data Base can contains package with documents in defined folder 

class Package 
{
  public:
   
  string staus_package;              // package can be public or private
  
  bool conection;
  
  private:

  // crearte text file 

  int crearte_text_file()
  {
    ofstream fout("document.txt");
    fout.close();
    return 0;
  }
  // delete text file 
  int delete_text_file()
  {
    delete(fout);
    return 0;
  }
  // get text file in begin  
  int crearte_document_repository (fout)
  {
    string name_ofrepository;
   
   // while we dont name of repository
    while ( name_ofrepository == "")
    {
       cout<<"Enter name of repository:";
       cin>>name_ofrepository;


    }  
     
    if (Check_box1.Set_status == true)  // with help of checkbox we choose status
    {
      status_package ="private";
    } 
    if (Check_box2.Set_status == true )
    {
      status_package ="public";
    }
    
    return 0;
  }

 // any package must has sppp adrress
  int get_adrress_SPPP()
  {  
    // in begin options of serser is turned out 
  
     get_status_of_conection (conection);

    do {
        string name_of_user_in_package = get_name_of_the_user();
        string generate_random_adrress (){
             
             string country_for_SPPP;
             cout<<"Your country ";
             cin>>country_for_SPPP;

             if (country_for_SPPP == "Russia")
             {
               int furst_number_of_SPPP = 100; 
             }
             else (country_for_SPPP == "Belarus")
             {
               int furst_number_of_SPPP = 101;
             }
             else (country_for_SPPP == "Chezh Republic")
             {
                int furst_number_of_SPPP = 102;
             }
             else (country_for_SPPP == "Sweden")
             {
                 int furst_number_of_SPPP = 103;
             }

             second_number_of_SPPP = 1+rand()%14525353463651435526357885769;
             
             third_number_of_SPPP = 1+rand()%1244132352;

             furth_number_of_SPPP = 1+rand()%1143513252;

             fivth_number_of_SPPP = 1+rand()%1234554464; 

             six_number_of_SPPP = 1+rand()%1143152554;

             seven_number_of_SPPP = 1+rand()%141425235235;

              string SPPP = furst_number_of_SPPP + "."+ second_number_of_SPPP +"."+third_number_of_SPPP+"."+furth_number_of_SPPP+"."+fivth_number_of_SPPP+"."+six_number_of_SPPP+"."+seven_number_of_SPPP;


           return SPPP;  
        } 
       

    }while (conection = false);
    
    string adress_spp = SPPP;
    return adress_spp;
  }


};

class PQCORE_EXPORT pqAnimationCue : public pqProxy
{
  Q_OBJECT
  typedef pqProxy Superclass;

public:
  pqAnimationCue(const QString& group, const QString& name, vtkSMProxy* proxy, pqServer* server,
    QObject* parent = NULL);
  ~pqAnimationCue() override;

  // Returns the number of keyframes in this cue.
  int getNumberOfKeyFrames() const;

  // Returns a list of the keyframes.
  QList<vtkSMProxy*> getKeyFrames() const;

  // Insert a new keyframe at the given index.
  // The time for the key frame is computed using the times
  // for the neighbouring keyframes if any.
  // Returns the newly created keyframe proxy on success,
  // NULL otherwise.
  vtkSMProxy* insertKeyFrame(int index);

  // Deletes the keyframe at the given index.
  // Consequently, the keyframesModified() signal will get fired.
  void deleteKeyFrame(int index);

  // Returns keyframe at a given index, if one exists,
  // NULL otherwise.
  vtkSMProxy* getKeyFrame(int index) const;

  // Returns the animated proxy, if any.
  vtkSMProxy* getAnimatedProxy() const;

  // Returns the property that is animated by this cue, if any.
  vtkSMProperty* getAnimatedProperty() const;

  // Returns the index of the property being animated.
  int getAnimatedPropertyIndex() const;

  /**
  * Set the type of the keyframe created by default.
  * default is CompositeKeyFrame.
  */
  void setKeyFrameType(const QString& type) { this->KeyFrameType = type; }

  /**
  * Used by editors to trigger keyframesModified() signal after bulk of
  * modifications have been made to the cue/key frames.
  */
  void triggerKeyFramesModified() { emit this->keyframesModified(); }

  /**
  * Get/Set the enabled state for the cue.
  */
  void setEnabled(bool enable);
  bool isEnabled() const;

signals:
  // emitted when something about the keyframes changes.
  void keyframesModified();

  // Fired when the animated proxy/property/index
  // changes.
  void modified();

  /**
  * Fired when the enabled-state of the cue changes.
  */
  void enabled(bool);

private slots:
  /**
  * Called when the "Enabled" property is changed.
  */
  void onEnabledModified();

private:
  Q_DISABLE_COPY(pqAnimationCue)

  /**
  * Methods used to register/unregister keyframe proxies.
  */
  void addKeyFrameInternal(vtkSMProxy*);
  void removeKeyFrameInternal(vtkSMProxy*);
  QString KeyFrameType;
};
#endif

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
      return salary_method;
    break;
    case 2:
      constable_salary();
      int salary_method = constable_salary();
      return salary_method;
    break;
    case 3:
      any_salary();
      int salary_method = any_salary();
      return salary_method;
    break    
    default:
    cout<<" Method doesn't exist "<<endl; 
   break;
  } 

   User employee;
  employee.get_name_of_the_user();
  employee.get_second_name_of_the_user();
  employee.get_age_of_the_user();
  employee.get_gender_of_the_user();
  employee.get_the_role_of_user();
  employee.salary_method;

  // condition  to eaqual names , user may not  to have equal name and second name 
  if ( name == second_name )
  {
    cout<<"impossible "<<endl;
  }   
  // return user
   return employee;
 }  
 
 //function of creating of repository
 long int button_create_repository ()
 {
   Package repository;
   repository.crearte_document_repository();
   repository.get_address_SPPP();
  
   return  repository;
 }
 
  void button_delete_user()
  {
    delete(employee);
  }
  
  void button_delete_repository()
  {
    delete(repository);
  }
  return 0;
}