#include<iostream>
using namespace std;
class Employee
{
private:
    int salary;
    int id;
    static int counter;
public:
    void set_salary();
    void get_salary();
    void set_id();
    void get_id();
    static void count(){
        cout<<"The number of employees till now is : "<<counter<<endl;
    }
};

int Employee ::counter;


void Employee :: set_id()
{
    cout<<"Enter id for employee "<<counter+1<<" : "<<endl;
    cin>>id;
}

void Employee :: set_salary()
{
    cout<<"Enter salary for employee "<<counter+1<<endl;
    cin>>salary;
    counter++;
}

void Employee :: get_salary(){
    cout<<"Salary of employee "<<counter<<" is :"<<salary<<endl;
    
}


void Employee :: get_id(){
    cout<<"Id of employee "<<counter<<" is :  "<<id<<endl;
}


int main(){

    Employee daniya,ayaan,zaviyar;
    daniya.set_id();
    daniya.set_salary();
    daniya.get_id();
    daniya.get_salary();
    Employee:: count();

    ayaan.set_id();
    ayaan.set_salary();
    ayaan.get_id();
    ayaan.get_salary();
    Employee:: count();
    
    zaviyar.set_id();
    zaviyar.set_salary();
    zaviyar.get_id();
    zaviyar.get_salary();
    Employee:: count();

    return 0;
}