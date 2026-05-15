#include<iostream>
#include<fstream>
using namespace std;

int main(){
    
    string s;
    cout<<"Enter any string : ";
    getline(cin,s);
    
    int size=s.size();
    
    ofstream outfile("string.txt");
    if (!outfile.is_open()){
        cout<<"No such file exists."<<'\n';
    }
    else{
        outfile<<s;
        outfile.close();
    }
    
    ifstream infile("string.txt");
    if(!infile.is_open()){
        cout<<"No such file exists."<<'\n';
    }
    else{
        char c;
        while(!infile.eof()){
            c=infile.get();
            cout<<c;
        }
        cout<<'\n';
        infile.close();
    }
    
    return 0;
}