#include<iostream>
using namespace std;
class Complex{
  int *real;
  int *imag;
  
  public:
    Complex(){
      real=NULL;
      imag=NULL;
    }
    
    Complex(int r,int i){
      real=new int (r);
      imag=new int (i);
    }
    
    Complex(const Complex& obj){
      real=new int (*obj.real);
      imag=new int (*obj.imag);
    }
    
    void display(){
      cout<<"The complex number is : "<<*real<<"+"<<*imag<<"i"<<endl;
    }
    
    void update(int r,int i){
      real=new int (r);
      imag=new int (i);
    }
    
    ~Complex(){
      delete real;
      delete imag;
    }
    
};

int main(){
  Complex c1(2,5);
  c1.display();
  Complex c2(c1);
  c2.display();
  c1.update(9,7);
  c1.display();
  c2.display();
  
  return 0;
}