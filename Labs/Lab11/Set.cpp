#include<iostream>
#include<set>
using namespace std;
class Guests{
  private:
    set<string>guests;
  public:
    Guests(){
        string name;
        char answer;
        do{
            cout<<"Enter the name of the guests : ";
            cin>>name;
            cout<<endl;
            guests.insert(name);
            cout<<"Do you want to add more guests (y/n) : ";
            cin>>answer;
            cout<<endl;
        }
        while(answer!='n');
    }
    void display_guests(){
        if(!guests.empty()){
            cout<<"-------------Displaying list of all the guests attending the party------------"<<endl;            for (string guest : guests){
                cout<<guest<<endl;
            }
        }
        else{
            cout<<"Guest list is empty."<<endl;
        }
    }
    
    void count_guests(){
        if(!guests.empty()){
            cout<<"There are total  "<<guests.size()<<" guests attending the party"<<endl;
        }
        else{
            cout<<"Guest list is empty."<<endl;
    }
}
};

int main(){
    Guests party;
    party.display_guests();
    party.count_guests();
    return 0;
    
}