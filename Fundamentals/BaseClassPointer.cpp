#include <iostream>
using namespace std;
class Person{
    public:
    virtual void draw() {
        cout<<"Aperson can draw"<<endl;
    };
    
};
class Artist : public Person{
    public:
    void draw () override {
        cout<<"Artist can draw with brushes"<<endl;
    }
};
class Gunman:public Person{
    public:
    void draw () override{
        cout<<"Gunman can draw bullets from gun"<<endl;
    }
};
int main() {
    Person* p[1];
    p[0]=new Artist();
    p[1]=new Gunman();
    p[0]->draw();
    p[1]->draw();

    return 0;
}