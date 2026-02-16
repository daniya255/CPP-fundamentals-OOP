#include <iostream>
#include<math.h>
using namespace std;
class Vector{
    private:
        int x,y;
    public:
        Vector() : x(0),y(0) {}
        Vector(int x,int y){
            this->x=x;
            this->y=y;
        }
        Vector operator + (Vector v){
            int a=x+v.x;
            int b=y+v.y;
            return Vector(a,b);
        }
        Vector operator - (Vector v){
            int a=x-v.x;
            int b=y-v.y;
            return Vector(a,b);
        }
        Vector operator * (int value){
            int a=x*value;
            int b=y*value;
            return Vector(a,b);
        }
        Vector operator / (int value){
            int a=x/value;
            int b=y/value;
            return Vector(a,b);
        }
        void magnitude(){
            float mag=sqrt(x*x+y*y);
            cout<<"Magnitude is : "<<mag<<endl;
        }
        void display(){
            cout<<"The vector is  : ("<<x<<","<<y<<")"<<endl;
        }
        
    
};
int main() {
    Vector v1(2,5);
    Vector v2(4,3);
    Vector sum=v1+v2;
    sum.display();
    Vector product=v1*5;
    product.display();
    v1.magnitude();
    
    return 0;
}