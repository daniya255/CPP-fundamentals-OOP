#include <iostream>
#include <string>
using namespace std;

template <class T>
class mycontainer {
    T element;
public:
    mycontainer(T e) : element(e) {}
    
    void increase() {
        element++;
    }

    void display() {
        cout << "Value: " << element << endl;
    }
};

template <>
class mycontainer<char> {
    char element;
public:
    mycontainer(char c) : element(c) {}

    void uppercase() {
        if (element >= 'a' && element <= 'z') {
            element += ('A' - 'a');
        }
    }

    void display() {
        cout << "Char Value: " << element << endl;
    }
};

int main() {
    mycontainer<int> myint(7);
    mycontainer<char> mychar('e');

    myint.increase();
    mychar.uppercase();

    myint.display();
    mychar.display();

    return 0;
}