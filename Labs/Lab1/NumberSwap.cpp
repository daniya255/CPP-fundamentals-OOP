#include <iostream>
using namespace std;
int main() {
    int a,b,c;
    
    cout<<"Enter any number : ";
    cin>>a;
    
    cout<<"Enter any number : ";
    cin>>b;
    
    cout<<"Enter any number : ";
    cin>>c;
    
    cout<<"The number before swapping are..."<<endl;
    cout<<"a= "<<a<<endl;
    cout<<"b= "<<b<<endl;
    cout<<"c= "<<c<<endl;
    
    
    int* ptra=&a;
    int* ptrb=&b;
    int* ptrc=&c;
    
    int temp=*ptra;
    *ptra=*ptrb;
    *ptrb=*ptrc;
    *ptrc=temp;
    
    cout<<"The number after swapping are..."<<endl;
    cout<<"a= "<<a<<endl;
    cout<<"b= "<<b<<endl;
    cout<<"c= "<<c<<endl;
    
    
    return 0;
}