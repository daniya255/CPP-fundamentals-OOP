#include<iostream>
#include<string>
using namespace std;

class EncryptionTechnique{
  protected:
    string msg;
  public:
    EncryptionTechnique(string msg) : msg(msg) {}
    virtual void encrypt() = 0;
    virtual void display() = 0;
    virtual ~EncryptionTechnique() {}
};

class EncryptionTechnique1 : virtual public EncryptionTechnique{
  public:
    string encrypted_msg=" ";
    EncryptionTechnique1(string msg) : EncryptionTechnique(msg) {}
    void encrypt() override{
      for(int i=0;i<(int)msg.size();i++){
        int ascii=(int)msg[i];
        encrypted_msg+=to_string(ascii)+ " ";
      }
    }
    void display() override{
      cout<<"Encrypted message by technique 1 : "<<encrypted_msg<<endl;
    };
    
};

class EncryptionTechnique2: virtual public EncryptionTechnique{
  public:
  string encrypted_msg = " ";
    EncryptionTechnique2(string msg) : EncryptionTechnique(msg) {}
    void encrypt() override{
      for(int i=0;i<(int)msg.size();i++){
        int ascii=(int)msg[i]+2;
        encrypted_msg+=to_string(ascii)+ " ";
      
    }
    }
    void display() override{
      cout<<"Encrypted message by technique 2 : "<<encrypted_msg<<endl;
    };
};
int main(){
  EncryptionTechnique1 * tech1 = new EncryptionTechnique1("Daniya");
  EncryptionTechnique2* tech2=new EncryptionTechnique2("Daniya");
  tech1->encrypt();
  tech2->encrypt();
  tech1->display();
  tech2->display();
  
  delete tech1;
  delete tech2;
  return 0;
}
