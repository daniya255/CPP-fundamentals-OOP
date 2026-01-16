#include<iostream>
using namespace std;
class EmployeePosition;
class EmployeePay{
    int salary;
    public:
        friend void discount (EmployeePay a,EmployeePosition b);
        void set_salary(int s){
            salary=s;
        }

        void get_salary(){
            cout<<"Your salary is Rs."<<salary<<endl;
        }
};

class EmployeePosition{
    string post;
    public:
        friend void discount(EmployeePay a,EmployeePosition b);
        void set_post(string p){
            post=p;
        }

        void get_post(){
            cout<<"Your are currently serving as the "<<post<<" in the company"<<endl;

        }
};

void discount(EmployeePay a,EmployeePosition b){
    if (a.salary>=40000 || b.post=="Senior manager"){
        cout<<"Your bonus amount is Rs."<<a.salary*0.5<<endl;
    }
    else if (a.salary>=25000 || b.post=="Manager"){
        cout<<"Your bonus amount is Rs."<<a.salary*0.4<<endl;
    }
    else
        cout<<"Your bonus amount is Rs."<<a.salary*0.25<<endl;


    
}

int main(){
    EmployeePay saim_pay;
    saim_pay.set_salary(22000);
    saim_pay.get_salary();

    EmployeePosition saim_post;
    saim_post.set_post("Manager");
    saim_post.get_post();
    discount(saim_pay,saim_post);

    return 0;
}
