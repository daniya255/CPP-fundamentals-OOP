#include <iostream>
#include <string>
using namespace std;

class Store {
protected:
    double total_bill;
public:
    Store(double bill) : total_bill(bill) {}
    virtual void calculateFinalBill() = 0;
    virtual ~Store() {}
};

class ImtiazStore : public Store {
public:
    ImtiazStore(double bill) : Store(bill) {}
    void calculateFinalBill() override {
        double discount = total_bill * 0.07;
        double final_bill = total_bill - discount;
        cout << "ImtiazStore (7% Discount):" << endl;
        cout << "Original Bill: " << total_bill << endl;
        cout << "Final Bill: " << final_bill << endl << endl;
    }
};

class BinHashimStore : public Store {
public:
    BinHashimStore(double bill) : Store(bill) {}
    void calculateFinalBill() override {
        double discount = total_bill * 0.05;
        double final_bill = total_bill - discount;
        cout << "BinHashimStore (5% Discount):" << endl;
        cout << "Original Bill: " << total_bill << endl;
        cout << "Final Bill: " << final_bill << endl << endl;
    }
};

int main() {
    double amount = 5000.0;

    Store* s1 = new ImtiazStore(amount);
    Store* s2 = new BinHashimStore(amount);

    s1->calculateFinalBill();
    s2->calculateFinalBill();

    delete s1;
    delete s2;

    return 0;
}