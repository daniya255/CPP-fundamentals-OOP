#include <iostream>
using namespace std;
class binary{

    private:
    string n;
    void is_bin();

    public:
    void get_bin();
    void one_complement();
    void display();
};
void binary :: is_bin(){
    for(int i=0;i<n.length();i++){
        if (n.at(i)!='0' && n.at(i)!='1'){
            cout<<"Invalid binary number entered"<<endl;
            exit(0);
        }
    }
    
}

void binary :: get_bin(){
    cout<<"Enter a binary number : ";
    cin>>n;
    is_bin(); 
}

void binary :: one_complement(){
    cout<<"Performing one's complement on your binary number."<<endl;
    for (int i=0;i<n.length();i++){
        if (n.at(i)=='0')
            n.at(i)='1';
        else
            n.at(i)='0';
    }
}

void binary :: display(){
    cout<<"Displaying your binary number"<<endl;
    for (int i=0;i<n.length();i++){
        cout<<n.at(i);
    }
}


int main(){

        binary b;
        b.get_bin();
        b.one_complement();
        b.display();

    return 0;
}