#include<iostream>
using namespace std;
class Constant{
  private:
    const string password;
    string name;
    string age;
  public:
    Constant(string passcode) : password(passcode) {}
    void set_info(){
      cout<<"Enter your name : ";
      cin>>name;
      cout<<"Enter your age : ";
      cin>>age;
    }
    
    void get_password() const{
      cout<<"Your password is : "<<password<<endl;
    }
    
    void get_info(){
      cout<<"Name : "<<name<<endl;
      cout<<"Age : "<<age<<endl;
    }
    
  
};
int main(){
  Constant c("drQe32$");
  c.set_info();
  c.get_password();
  c.get_info();
  return 0;
}