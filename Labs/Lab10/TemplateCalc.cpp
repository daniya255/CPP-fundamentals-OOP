#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Calculator {
private:
    T1 num1;
    T2 num2;

public:
    Calculator(T1 n1, T2 n2) : num1(n1), num2(n2) {}

    void displayResults() {
        cout << "Numbers: " << num1 << " and " << num2 << endl;
        cout << "Sum: " << num1 + num2 << endl;
        cout << "Difference: " << num1 - num2 << endl;
        cout << "Product: " << num1 * num2 << endl;
        if (num2 != 0)
            cout << "Division: " << (double)num1 / num2 << endl;
        else
            cout << "Division: Cannot divide by zero" << endl;
        
    }
};

int main() {

    Calculator<int, int> calc1(10, 5);
    calc1.displayResults();

    Calculator<int, double> calc2(10, 2.5);
    calc2.displayResults();

    return 0;
}