#include <iostream>
using namespace std;

template <typename T1, typename T2>
void swapData(T1 &a, T2 &b) {

    T1 temp = a;
    a = (T1)b;
    b = (T2)temp;
}

int main() {
    int x = 10, y = 20;
    cout << "Before swap (int): x = " << x << ", y = " << y << endl;
    swapData(x, y);
    cout << "After swap (int):  x = " << x << ", y = " << y << endl;

    cout << endl;

    int p = 5;
    double q = 9.99;
    cout << "Before swap (mixed): p = " << p << ", q = " << q << endl;
    swapData(p, q); 
    cout << "After swap (mixed):  p = " << p << ", q = " << q << endl;

    return 0;
}