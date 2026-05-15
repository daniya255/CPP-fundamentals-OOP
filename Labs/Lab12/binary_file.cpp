#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
class Person {
private:
	char name[49];
	int age;
public:
	Person() : age(0) {
		name[0]='\n';
	}
	Person(string n,int a) : age(a) {
		strncpy(name,n.c_str(),49);
		name[49]='\0';
	}

	void display() {
		cout<<"Name : "<<name<<endl;
		cout<<"Age : "<<age<<endl;
	}

};

int main() {
	Person p1("Daniya",18);
	ofstream f("person.bin",ios::binary);
	if(f.is_open()) {
		f.write(reinterpret_cast<char *>(&p1),sizeof(p1));
		cout<<endl;
		f.close();
	}
	else {
		cout<<"File not found."<<endl;
	}


	Person p2;

	ifstream d("person.bin",ios::binary);
	if(d.is_open()) {
		d.read(reinterpret_cast<char *>(&p2),sizeof(p2));
		if(d) {
			p2.display();
			d.close();
		}
	}
	else {
		cout<<"File not found."<<endl;
	}

	return 0;
}