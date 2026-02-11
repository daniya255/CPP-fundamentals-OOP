#include<iostream>
using namespace std;
class classTeacher{
  string name,institute;
  int age;
  public:
    void set_name(string name){
      this->name=name;
    }
    
    void set_age(int age){
      this->age=age;
    }
    
    void set_institute(string institute){
      this->institute=institute;
    }
    
    void get_name(){
      cout<<"The name of the teacher is "<<name<<endl;
    }
    
    void get_institute(){
      cout<<"The name of the institute the teacher is associated with is "<<institute<<endl;
    }
    
    void get_age(){
      cout<<"The age of the teacher is "<<age<<endl;
    }
};

class HumanitiesTeacher: public classTeacher{
  string department="humanities";
  string designation,course_name;
  public:
    void set_designation(string designation){
      this->designation=designation;
    }
    void set_courseName(string course_name){
      this->course_name=course_name;
    }
     void get_department(){
      cout<<"The department of the teacher is "<<department<<endl;
    }
     void get_designation(){
      cout<<"The designation of the teacher is "<<designation<<endl;
    }
     void get_courseName(){
      cout<<"The course name of the teacher is "<<course_name<<endl;
    }
};

class MathsTeacher: public classTeacher{
  string department="mathematics";
  string designation,course_name;
  public:
    void set_designation(string designation){
      this->designation=designation;
    }
    void set_courseName(string course_name){
      this->course_name=course_name;
    }
     void get_department(){
      cout<<"The department of the teacher is "<<department<<endl;
    }
     void get_designation(){
      cout<<"The designation of the teacher is "<<designation<<endl;
    }
     void get_courseName(){
      cout<<"The course name of the teacher is "<<course_name<<endl;
    }
};

class ScienceTeacher : public classTeacher{
  string department="science";
  string designation,course_name;
  public:
    void set_designation(string designation){
      this->designation=designation;
    }
    void set_courseName(string course_name){
      this->course_name=course_name;
    }
     void get_department(){
      cout<<"The department of the teacher is "<<department<<endl;
    }
     void get_designation(){
      cout<<"The designation of the teacher is "<<designation<<endl;
    }
     void get_courseName(){
      cout<<"The course name of the teacher is "<<course_name<<endl;
    }
};

int main(){
  
  // MathsTeacher object
  MathsTeacher m1;
  m1.set_name("Shahzaib");
  m1.set_institute("NED");
  m1.set_designation("Professor");
  m1.set_courseName("Calculus");
  m1.set_age(34);
  m1.get_name();
  m1.get_institute();
  m1.get_department();
  m1.get_designation();
  m1.get_age();
  m1.get_courseName();
  
  // HumanitiesTeacher obj
  HumanitiesTeacher h1;
  h1.set_name("Ayesha");
  h1.set_institute("SUFA");
  h1.set_designation("Lecturer");
  h1.set_courseName("Civic sense");
  h1.set_age(27);
  h1.get_name();
  h1.get_institute();
  h1.get_department();
  h1.get_designation();
  h1.get_age();
  h1.get_courseName();
  
  // ScienceTeacher obj
  ScienceTeacher s1;
  s1.set_name("Mehwish");
  s1.set_institute("IOBM");
  s1.set_designation("Lecturer");
  s1.set_courseName("Applied Pyhsics");
  s1.set_age(40);
  s1.get_name();
  s1.get_institute();
  s1.get_department();
  s1.get_designation();
  s1.get_age();
  s1.get_courseName();
  
  
  return 0;
}