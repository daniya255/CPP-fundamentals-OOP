#include<iostream>
using namespace std;
class Base{
  private:
    int privateInt;
  protected:
    int protectedInt;
  public:
    int publicInt;
  
  void set_privateInt(int priv){
    privateInt=priv;
  }
  
  void set_protectedInt(int pro){
    protectedInt=pro;
  }
  
  void set_publicInt(int pub){
    publicInt=pub;
  }
  
  void get_privateInt(){
    cout<<"The value of private integer variable is : "<<privateInt<<endl;
  }
  
   void get_protectedInt(){
    cout<<"The value of protected integer variable is : "<<protectedInt<<endl;
  }
  
   void get_publicInt(){
    cout<<"The value of public integer variable is : "<<publicInt<<endl;
  }
  
  
};

class publicChild: public Base{
  //privateInt=5    cannot access the privateInt variable without setter and getter
  //protectedInt=6  access protectedInt inside the class but not outside it
  //publicInt=9     is accessible inside and outside the derived class.
  
}; 

class privateChild: private Base{
  
   //privateInt=5    cannot access the privateInt variable without setter and getter
  //protectedInt=6   cannot access the privateInt variable without setter and getter
  //publicInt=9      cannot access the privateInt variable without setter and getter
 
};

class protectedChild: protected Base{
  //privateInt=5    cannot access the privateInt variable without setter and getter
  //protectedInt=6  access protectedInt inside the class but not outside it
  //publicInt=9     become protected and can be accessed within the derived class
  
};
int main(){
  // privateChild op;   will give error
  // op.privateInt=8;
  // publicChild op1;   will give error
  // op1.privateInt=9;
  // protectedChild op2;  will give error
  // op2.privateInt=8;
  
  publicChild pub;
  pub.set_privateInt(9);
  pub.get_privateInt();
  pub.set_protectedInt(2);
  pub.get_protectedInt();
  pub.set_publicInt(6);
  pub.get_publicInt();
  
  return 0;
}