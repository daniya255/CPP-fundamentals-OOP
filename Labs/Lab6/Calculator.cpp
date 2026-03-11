#include<iostream>
using namespace std;
class Calculator{
    private:
        int num1,num2,num3;
    public:
        void add(int a,int b){
            cout<<"The reult of the addition operation is "<<a+b<<endl;
        }
        void add(int a,int b,int c){
            cout<<"The reult of the addition operation is "<<a+b+c<<endl;
        }
        void multiply(int a,int b){
            cout<<"The reult of the multiplication operation is "<<a*b<<endl;
        }
        void multiply(int a,int b,int c){
            cout<<"The reult of the multiplication operation is "<<a*b*c<<endl;
        }
        void subtract(int a,int b){
            cout<<"The result of subtraction of the operands is "<<a-b<<endl;
        }
        void division(int a,int b){
            if(b!=0){
                cout<<"The reult of the division operation is "<<a/b<<endl;
            }
        }
       
};
int main(){
    Calculator obj;
    obj.add(2,5);
    obj.subtract(9,6);
    obj.multiply(5,5,5);
    obj.division(10,5);
    return 0;
}