#include <iostream>
using namespace std;
class Person{
    private:
    string occupation;
    string name;
    public:
    Person(): occupation("NULL") {}
    Person(string o): occupation(o) {}
    void set_name(string name){
        this->name=name;
    }
    void set_occupation(string occupation){
        this->occupation=occupation;
    }
    void get_occupation(){
        cout<<"Occupation : "<<occupation<<endl;
    }
    void get_name(){
        cout<<"Name : "<<name<<endl;
    }
    virtual void draw(){
        cout<<"A person can draw in many ways"<<endl;
    }
    virtual ~Person(){}
};
class Artist : public Person{
  public:
    Artist() : Person("artist") {}
    void draw() override {
        cout<<"An artist can draw with a paint brush"<<endl;
    }
};
class GunMan : public Person{
  public:
    GunMan() : Person("gunman") {}
    void draw() override {
        cout<<"A gun man draws a gun to shoot"<<endl;
    }
};
    
int main() {
    Person *p[3];
    p[0]= new Person();
    p[1]= new Artist();
    p[2]=new GunMan();
    p[0]->draw();
    p[1]->draw();
    p[2]->draw();
    
    for (int i=0;i<3;i++){
        delete p[i];
    }

    return 0;
}