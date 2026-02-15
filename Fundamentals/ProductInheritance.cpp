#include <iostream>
using namespace std;
class Base{
  public:
    int x;
    void set_data(int a){
      x=a;
      
    }
};
class Derived1:public Base{
  public:
  int y;
    void read_data(int b){
      y=b;
    }
};

class Derived2: public Derived1{
  public:
    int z;
    void in_data(int c){
      z=c;
    }
    void product(){
      cout<<"The product is : "<<x*y*z<<endl;
    }
};

int main() 
{
    Derived2 obj;
    obj.set_data(5);
    obj.read_data(5);
    obj.in_data(5);
    obj.product();
    return 0;
}