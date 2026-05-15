#include<iostream>
#include<map>
using namespace std;
class Record{
  private:
    map<string,int>report;
public:
    Record(){
        string name;
        int grade;
        char answer;
        do{
            cout<<"Enter the name of the student : ";
            cin>>name;
            cout<<endl;
            cout<<"Enter the grade of the student : ";
            cin>>grade;
            cout<<endl;
            report[name]=grade;
            cout<<"Do you want to add more students (y/n) : ";
            cin>>answer;
            cout<<endl;
        }
        while(answer!='n');
    }
    void get_grade(string name){
        if(report.count(name)){
            cout<<name<<" : "<<report[name]<<endl;
        }
        else{
            cout<<"No such student exists"<<endl;
        }
    }
    void update_record(string name){
        if(report.count(name)){
            int grade;
            cout<<"Enter the new grade : ";
            cin>>grade;
            report[name]=grade;
            cout<<endl;
        }
        else{
            cout<<"No such student exists.."<<endl;
        }
    }
    void del_record(string name){
        if(report.count(name)){
            report.erase(name);
            cout<<"Record removed successfully."<<endl;
        }
        else{
            cout<<"No such student exists.."<<endl;
        }
    }
    void show_record(){
        if(!report.empty()){
            cout<<"----------Showing record of students----------"<<endl;
        for (auto student: report){
            cout<<student.first<<" : "<<student.second<<endl;
        }
        }
        else{
            cout<<"No record exits."<<endl;
        }
    }
};
int main(){
    Record secA;
    secA.get_grade("Ali");
    secA.update_record("Ayesha");
    secA.del_record("Ahmed");
    secA.show_record();
    return 0;
}