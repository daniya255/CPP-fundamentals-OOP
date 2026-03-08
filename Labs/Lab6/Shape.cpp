#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
class Shape{
    protected:
        int numberOfsides;
        float area;
    public:
        Shape(): area(0.0),numberOfsides(0) {}
        Shape(int n,float a): area(a),numberOfsides(n) {}
        void set_sides(int n){
            numberOfsides=n;
        }
        void get_sides(){
            cout<<"The number of sides of the shape are "<<numberOfsides<<endl;
        }
        void set_area(float a){
            area=a;
        }
        void get_area(){
            cout<<"The area of the shape is "<<fixed<<setprecision(2)<<area<<endl;
        }
        
};
class Rectangle : public Shape{
    protected:
        float length,width;
    public:
        Rectangle(): length(0),width(0) {
             numberOfsides=4;
        }
        Rectangle(float l,float w): length(l),width(w) {
             numberOfsides=4;
        }
        void generate_area(){
            area=length*width;
        }
};
class Circle : public Shape{
    protected:
        float radius;
    public:
        Circle(): radius(0) {
             numberOfsides=0;
        }
        Circle(float r): radius(r) {
             numberOfsides=0;
        }
        void generate_area(){
            area=3.141*pow(radius,2);
        }
};
class Triangle: public Shape{
    protected:
        float height,base;
    public:
        Triangle(): height(0),base(0) {
            numberOfsides=3;
        }
        Triangle(float h,float b): height(h),base(b) {
             numberOfsides=3;
        }
        void generate_area(){
            area=0.5*height*base;
        }
};
class Square: public Rectangle{
    public:
        Square(): Rectangle(0,0) {}
        Square(float n): Rectangle(n,n) {}
        void check_sides(){
            if (length!=width){
                return;
            }    
        }
        
};
int main() {
    Square sq (5);
    sq.generate_area();
    sq.get_area();
    return 0;
}