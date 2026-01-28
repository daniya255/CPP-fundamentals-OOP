#include <iostream>
using namespace std;
class EpicClash{
    int *health= new int;
    int *defense=new int;
    string *attack=new string;
    public:
        EpicClash(){
            *health=200;
            *defense=150;
            *attack="fire";
        }
        EpicClash(int h,int d,string a){
            *health=h;
            *defense=d;
            *attack=a;
        }
        EpicClash(const EpicClash&obj){
            *health=*(obj).health;
            *defense=*(obj).defense;
            *attack=*(obj).attack;
        }
        void set_abilities(int h,int d,string a){
             *health=h;
            *defense=d;
            *attack=a;
        }
        void get_abilities(){
            cout<<"The character's health is : "<<*health<<endl;
            cout<<"The character's defense power is : "<<*defense<<endl;
            cout<<"The character's attack is : "<<*attack<<endl;
        }
};
int main() {
    // EpicClash charizad;
    // charizad.get_abilities();
    // EpicClash pokemon(221,145,"Water");
    // pokemon.get_abilities();
    // EpicClash pikachu(pokemon);
    // pikachu.get_abilities();
    // pokemon.set_abilities(456,89,"Wind");
    // pokemon.get_abilities();
     return 0;
}