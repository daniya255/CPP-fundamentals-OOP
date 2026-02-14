#include<iostream>
using namespace std;
class HotelMercato{
  private:
    const float rent_day=100.85;
    int no_days;
    float rent;
    string customer_name;
    
  public:
     HotelMercato() : no_days(0), rent(0) {}
     HotelMercato(int days,string name) {
       this->customer_name=name;
       no_days=days;
     } 
     void set_info(){
       cout<<"Enter your name : ";
       cin>>customer_name;
       cout<<"Enter the number of days your stayed : ";
       cin>>no_days;
     }
     
     float calculate_rent(){
       if(no_days>7){
         rent=(no_days-1)*rent_day;
       }
       else{
         rent=no_days*rent_day;
       }
       return rent;
     }
    
    void display(){
      cout<<"_____________________________________"<<endl;
      cout<<"Customer Name : "<<customer_name<<endl;
      cout<<"Number of days stayed : "<<no_days<<endl;
      cout<<"Total Rent : Rs."<<calculate_rent()<<endl;
      cout<<"______________________________________"<<endl;
    }
     
};

int main(){
  HotelMercato obj;
  obj.set_info();
  obj.display();
  return 0;
}