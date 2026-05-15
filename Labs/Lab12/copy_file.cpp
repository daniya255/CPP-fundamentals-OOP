#include<iostream>
#include<fstream>
using namespace std;
class Record {
public:
	string name,city;
	int age;
	Record() {
		cout<<"Enter your name : ";
		getline(cin,name);
		cout<<'\n';
		cout<<"Enter your city : ";
		cin>>city;
		cout<<'\n';
		cout<<"Enter your age : ";
		cin>>age;
		cout<<'\n';
	}
	void return_record() {
		cout<<"Name : "<<name<<endl;
		cout<<"City : "<<city<<endl;
		cout<<"Age : "<<age<<endl;
	}

};

int main() {
	Record r;
	ofstream f("file1.dat");
	if(f.is_open()) {
		f<<r.name<<'\n';
		f<<r.age<<'\n';
		f<<r.city<<'\n';
		f.close();
	}

	ofstream d("file2.dat");
	if(d.is_open()) {
		ifstream f("file1.dat");
		string text;
		while(!getline(f,text).eof()) {
			d<<text<<'\n';
		}
		f.close();
		d.close();
	}
	return 0;

}

