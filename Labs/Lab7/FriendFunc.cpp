#include<iostream>
using namespace std;
class Employee{
  private:
    string name,designation;
    int id,salary;
 public:
    friend void IncreaseSalary(Employee& e,double);
    Employee(string n="XYZ",string d="None",int i=0,int s=0) : name(n),designation(d),id(i),salary(s) {}
    void set_info(){
        cout<<"Enter name : ";
        cin>>name;
        cout<<"Enter your designation : ";
        cin>>designation;
        cout<<"Enter the employee id : ";
        cin>>id;
        cout<<"Enter salary in ruppees : ";
        cin>>salary;
    }
    void get_info(){
        cout<<"Name : "<<name<<endl;
        cout<<"Designation : "<<designation<<endl;
        cout<<"ID : "<<id<<endl;
        cout<<"Salary : Rs."<<salary<<endl;
    }
};

void IncreaseSalary(Employee& e,double IncPercent){
    if(IncPercent>0 || IncPercent<=100){
        double increment=e.salary*(IncPercent/100);
        e.salary+=increment;
        cout<<"The salary for "<<e.name<<" has been updated."<<endl;
            }
        }

int main(){
    Employee e1;
    e1.set_info();
    cout<<"The record of the employee before increment is : "<<endl;
    e1.get_info();
    cout<<"-------------------------------------------------"<<endl;
    IncreaseSalary(e1,24.5);
    cout<<"-------------------------------------------------"<<endl;
    cout<<"The record of the employee after increment is : "<<endl;
    e1.get_info();
    
    return 0;
}