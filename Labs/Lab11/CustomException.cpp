#include<iostream>
#include<string>
#include<cctype>
#include<exception>
using namespace std;
class MyException : public exception{
private:
    string message;
  public:
  MyException(const string & msg) : message(msg) {}
  const char* what() const noexcept override {
        return message.c_str();
    }
};


class Login{
  private:
    string username,password;
 public:
  void len_pass(string password){ 
            if ((int)password.size()<6)
               throw MyException("Invalid Syntax : Password should be of 6 or more characters") ;
        }
void dig_pass(string password){
    bool flag=false;
    for (char c : password){
        if(isdigit(static_cast<unsigned char>(c))){
            flag=true;
            break;
    }
    }
    if (!flag){
    throw MyException("Syntax Error : Password must contain a digit");
}
}

Login(string u,string p) : username(u),password(p) {
        len_pass(password);
        dig_pass(password);
        cout<<"Login successfully.."<<endl;
    }
    
};

int main(){
    try{
    Login login("Daniya","password");
    }
    catch (const MyException & e){
        cerr<<e.what()<<endl;
    }
    return 0;
}