#include <iostream>
using namespace std;
class Account{
  private:
    string name;
    long account_no;
    int account_balance,security_code;
    static int obj_no;
  public:
    void set_info(){
      cout<<"Enter your name : ";
      cin>>name;
      cout<<"Enter your account number : ";
      cin>>account_no;
      cout<<"Enter your account balance : Rs.";
      cin>>account_balance;
      cout<<"Enter your security code : ";
      cin>>security_code;
      obj_no+=1;
    }
    
    void get_info(){
      cout<<"The name of the account holder is  : "<<name<<endl;
      cout<<"The account number is  : "<<account_no<<endl;
      cout<<"The account balance is Rs."<<account_balance<<endl;
      cout<<"The security code is : "<<security_code<<endl;
    }
    
    static void get_objCreated() {
      cout<<"The number of objects created till now are : "<<obj_no<<endl;
    }
    
};

int Account:: obj_no=0;

int main() 
{
  Account obj1,obj2,obj3;
  obj1.set_info();
  obj1.get_info();
  obj2.set_info();
  obj3.set_info();
  Account:: get_objCreated();
  
    return 0;
}