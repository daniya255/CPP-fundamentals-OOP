#include <iostream>
#include<vector>
using namespace std;
class Employee{
    vector<char>first_name;
    string last_name;
    int salary;
    
    public:
        Employee():first_name(20){} //constructor
        
        void set_record(char fname[20],string lname,int salary){
            first_name.clear();
            for (int i=0;fname[i]!='\0' && i<20;i++){
                first_name.push_back(fname[i]);
            }
            last_name=lname;
            if(salary>0){
                this->salary=salary;
            }
            else
                this->salary=0;
        }
        
        void get_record(){
            cout<<"The name of the employee is ";
            for (char c:first_name){
                cout<<c;
            }
            cout<<" "<<last_name<<endl;
            for (char c:first_name){
                cout<<c;
            }
            cout<<"'s monthly salary is Rs."<<salary<<endl;
        }
        
};
int main() {
    Employee e1;
    char fname[20]="Daniya";
    e1.set_record(fname,"Ali",48000);
    e1.get_record();
    

    return 0;
}