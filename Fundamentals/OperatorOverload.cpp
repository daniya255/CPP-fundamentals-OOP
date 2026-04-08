
#include <iostream>
using namespace std;
class complex{
    private:
    int real,img;
    public:
    complex (int r=0,int img=0) : real(r),img(img) {}
       complex operator + (complex &c2){
            complex result;
            result.real=this->real+c2.real;
            result.img=this->img+c2.img;
            return result;
        }
        complex operator - (complex &c2){
            complex result;
            result.real=this->real-c2.real;
            result.img=this->img-c2.img;
            return result;
        }
        void display(){
            cout<<"The complex number is : "<<real<<"+"<<img<<"i"<<endl;
        }
        
};
int main() {
    complex c1(2,3);
    complex c2(4,8);
    complex result;
    result=c1+c2;
    result.display();

    return 0;
}