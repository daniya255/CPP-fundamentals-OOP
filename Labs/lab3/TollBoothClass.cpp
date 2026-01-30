#include<iostream>
using namespace std;
class TollBooth{
  int no_cars;
  double money_collected;
  
  public:
  
  TollBooth(): no_cars(0),money_collected(0){}
  
  void payingCar(){
    no_cars++;
    money_collected+=0.5;
  }
  
  void getTotal(){
    cout<<"The total number of cars passed the tollbooth are : "<<no_cars<<endl;
    cout<<"The total amount of cash collected is Rs."<<money_collected<<endl;
  }

    
};

int main(){
  TollBooth obj1;
  obj1.payingCar();
  obj1.payingCar();
  obj1.getTotal();
  return 0;
}