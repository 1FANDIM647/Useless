
// Business logic of Data Base
#include <iostream>
#include <string>


using namespace std;


class Customer {

public:
    // create customer
    void create_customer()
    {    
          string name_of_customer , type_of_service;
          int price;
          double time;  

          cout<<"name of customer:"<<endl;
          cin>>name_of_customer;
          cout<<"type of service:"<<endl;
          cin>>type_of_service;
          cout<<"price of service"<<endl;
          cin>>price;
          cout<<"time:"<<endl;
          cin>>time;
    }

};

class Order{

public :
     //create customer
    void create_order()
    {
       string service_order;
       int price_of_service;

       cout<<"type of service:"<<endl;
       cin>>service_order;
       cout<<"price"<<endl;
       cin>>price_of_service;
    }

};

// create objects 
int main()
{
   Customer Jhon;
   Jhon.create_customer();

   Order Photo;
   Photo.create_order();

return 0;
    
}