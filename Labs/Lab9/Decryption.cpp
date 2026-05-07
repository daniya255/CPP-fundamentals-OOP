#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class DecryptionTechnique{
  protected:
    string msg;
  public:
    DecryptionTechnique(string msg) : msg(msg) {}
    virtual void decrypt() = 0;
    virtual void display() = 0;
    virtual ~DecryptionTechnique() {}
};

class DecryptionTechnique1 : virtual public DecryptionTechnique{
  public:
    string decrypted_msg="";
    DecryptionTechnique1(string msg) : DecryptionTechnique(msg) {}
    void decrypt() override{
      stringstream ss(msg);
      int ascii;
      while(ss>>ascii){
        decrypted_msg+=(char)ascii;
      }
    }
    void display() override{
      cout<<"Decrypted message by technique 1 : "<<decrypted_msg<<endl;
    };
    
};

class DecryptionTechnique2: virtual public DecryptionTechnique{
  public:
  string decrypted_msg = "";
    DecryptionTechnique2(string msg) : DecryptionTechnique(msg) {}
    void decrypt() override{
      stringstream ss(msg);
      int ascii;
      while(ss>>ascii){
        ascii=ascii-2;
        decrypted_msg+=(char)ascii;
      }
    }
    void display() override{
      cout<<"Decrypted message by technique 2 : "<<decrypted_msg<<endl;
    };
};
int main(){
  DecryptionTechnique1 * tech1 = new DecryptionTechnique1("68 97 110 105 121 97");
  DecryptionTechnique2 * tech2 = new DecryptionTechnique2("70 99 112 107 123 99");
  tech1->decrypt();
  tech2->decrypt();
  tech1->display();
  tech2->display();
  
  delete tech1;
  delete tech2;
  return 0;
}
