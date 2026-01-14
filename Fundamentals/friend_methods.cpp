#include<iostream>
using namespace std;
class Complex{
    int a,b;
    public:
        friend  Complex addComplex(Complex c,Complex d);
        void setNumber(int v1,int v2){
            a=v1;
            b=v2;
        }

        void displayNumber(){
            cout<<"The complex number is : "<<a<<" + "<<b<<"i"<<endl;
        }
};

Complex addComplex(Complex c,Complex d){
    Complex e;
    e.a=c.a+d.a;
    e.b=c.b+d.b;
    return e;

}

int main(){

    Complex c1,c2,c3;
    c1.setNumber(5,8);
    c1.displayNumber();

    c2.setNumber(4,16);
    c2.displayNumber();

    c3=addComplex(c1,c2);
    c3.displayNumber();

    return 0;
}
