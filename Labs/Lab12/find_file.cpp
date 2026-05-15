#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

class Participant {
private:
	string name;
	int id,score;

public:
	Participant() : name("null"),id(0),score(0) {}
	Participant(string n, int i, int s) : name(n), id(i), score(s) {}
	void set_info() {
		cout<<"Enter name : ";
		cin>>name;
		cout<<'\n';

		cout<<"Enter id : ";
		cin>>id;
		cout<<'\n';

		cout<<"Enter score : ";
		cin>>score;
		cout<<'\n';

		ofstream f("participant.dat",ios::app);

		if (f.is_open()) {
			f<<id<<'|';
			f<<name<<'|';
			f<<score<<'\n';

			f.close();
		}
	}

	void see_info() {

		int num;
		cout<<"Enter the id number : ";
		cin>>num;
		cout<<'\n';

		ifstream d("participant.dat");

		if(d.is_open()) {
			string text;
			bool flag=false;
			while(getline(d,text)) {
				stringstream ss(text);
				string id_str,name_str,score_str;

				if(getline(ss,id_str,'|')) {
					if(num==stoi(id_str)) {
						flag=true;
						cout<<"--------------Record found---------"<<endl;
						cout<<"ID : "<<id_str<<'\n';
						getline(ss,name_str, '|');
						cout<<"Name : "<<name_str<<endl;
						getline(ss,score_str);
						cout<<"Score : "<<score_str<<endl;
						d.close();
						break;
					}
				}

			}
			if(!flag) {
				cout<<"No such id found."<<endl;
			}
		}
		else {
			cout<<"File not found"<<endl;
		}

	}

	void max_id() {
		ifstream d("participant.dat");

		if(d.is_open()) {

			string current_id, current_name, current_score;
			string max_name, max_id;
			int max_score = -1;

			while (getline(d, current_id, '|')) {
				getline(d, current_name, '|');
				getline(d, current_score);


				if (max_score< stoi(current_score)) {
					max_score = stoi(current_score);
					max_name = current_name;
					max_id= current_id;
				}
			}

			if (max_score != -1) {
				cout << "--- Participant with Highest Score ---" << endl;
				cout << "ID: " << max_id << " | Name: " << max_name
				     << " | Score: " << max_score << endl;
				d.close();
			} else {
				cout << "No records found in file." << endl;
			}
		}

		else {

			cout<<"File not found"<<endl;

		}

	}

};



int main() {

	Participant a;
	a.set_info();
	a.see_info();
	a.max_id();


	return 0;

}