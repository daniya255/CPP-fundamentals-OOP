#include<iostream>
using namespace std;
class Complex;

class Calculator{
    public:

        Complex sumComp(Complex c1,Complex c2);
        Complex multiplyComp(Complex c1,Complex c2);
        Complex SubComp(Complex c1,Complex c2);
        
};


class Complex{
    int a,b;
    friend  Complex Calculator :: sumComp(Complex c1,Complex c2);
    friend Complex Calculator :: multiplyComp(Complex c1,Complex c2);
    friend Complex Calculator :: SubComp(Complex c1,Complex c2);


    public:
        void setNumber(int v1,int v2){
            a=v1;
            b=v2;
        }

        void displayNumber(){
            cout<<"The complex number is : "<<a<<" + "<<b<<"i"<<endl;
        }
};

Complex Calculator :: sumComp(Complex c1,Complex c2){
            Complex c3;
            c3.a=c1.a+c2.a;
            c3.b=c1.b+c2.b;
            return c3;
        }

Complex Calculator :: multiplyComp(Complex c1,Complex c2){
            Complex c3;
            c3.a=c1.a*c2.a;
            c3.b=c1.b*c2.b;
            return c3;
        }

Complex Calculator ::  SubComp(Complex c1,Complex c2){
            Complex c3;
            if (c1.a>c2.a){
                c3.a=c1.a-c2.a;
                c3.b=c1.b-c2.b;
            }
            else{
                c3.a=c2.a-c1.a;
                c3.b=c2.b-c1.b;
            }
            return c3;
        }

int main(){
    Complex op1,op2;
    op1.setNumber(2,3);
    op1.displayNumber();

    op2.setNumber(4,8);
    op2.displayNumber();

    Calculator sum_op,multiply_op,sub_op;

    Complex sumR=sub_op.sumComp(op1,op2);
    cout<<"Summing the numbers.."<<endl;
    sumR.displayNumber();

    Complex multiplyR=sub_op.multiplyComp(op1,op2);
    cout<<"Multiplying the numbers..."<<endl;
    multiplyR.displayNumber();

    Complex subR=sub_op.SubComp(op1,op2);
    cout<<"Subtracting the numbers..."<<endl;
    subR.displayNumber();


    return 0;
}