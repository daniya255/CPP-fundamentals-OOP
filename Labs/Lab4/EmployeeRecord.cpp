#include<iostream>
using namespace std;
class Employee{
    private:
        string name;
        int id;
    public:
        Employee(): id(0),name("XYZ") {}
        Employee(int num_id) : id(num_id) {}
        void set_name(string name){
            this->name=name;
        }
        void get_id(){
            cout<<"The employee's id is : "<<id<<endl;
        }
        void get_name(){
            cout<<"The employee's name is : "<<name<<endl;
        }
};

int main(){
    Employee Employee1(123);
    Employee1.set_name("Ali");
    Employee1.get_name();
    Employee1.get_id();
    
    Employee Employee2(124);
    Employee2.set_name("Ahmed");
    Employee2.get_name();
    Employee2.get_id();
    
    Employee Employee3(125);
    Employee3.set_name("Daniya");
    Employee3.get_name();
    Employee3.get_id();
    
    return 0;
}