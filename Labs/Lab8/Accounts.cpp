#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    double Balance;

public:

    Account() {
        cout << "Enter initial balance: ";
        cin >> Balance;
    }

    Account(double b) : Balance(b) {}

    virtual void deposit(double amount) {
        Balance += amount;
        cout << "Deposited: " << amount << " | New Balance: " << Balance << endl;
    }

    virtual void withdraw(double amount) {
        if (amount <= Balance) {
            Balance -= amount;
            cout << "Withdrawn: " << amount << " | New Balance: " << Balance << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void checkBalance() {
        cout << "Current Balance: " << Balance << endl;
    }

    double getBalance() const { return Balance; }
    void setBalance(double b) { Balance = b; }

    virtual ~Account() {}
};

class InterestAccount : virtual public Account {
protected:
    double Interest;

public:
    InterestAccount() : Account() {
        Interest = 0.30; 
    }

    InterestAccount(double b, double i = 0.30) : Account(b), Interest(i) {}

    void deposit(double amount) override {
        double interestAmount = amount * Interest;
        Balance += (amount + interestAmount);
        cout << "Deposited: " << amount << " with " << (Interest * 100) 
             << "% interest. New Balance: " << Balance << endl;
    }
};

class ChargingAccount : virtual public Account {
protected:
    double fee;

public:
    ChargingAccount() : Account() {
        fee = 25.0; 
    }

    ChargingAccount(double b, double f = 25.0) : Account(b), fee(f) {}

    void withdraw(double amount) override {
        double totalDeduction = amount + fee;
        if (totalDeduction <= Balance) {
            Balance -= totalDeduction;
            cout << "Withdrawn: " << amount << " (Fee: " << fee 
                 << "). New Balance: " << Balance << endl;
        } else {
            cout << "Insufficient balance to cover withdrawal and fee!" << endl;
        }
    }
};

class ACI : public InterestAccount, public ChargingAccount {
public:
    ACI() : Account(), InterestAccount(), ChargingAccount() {}

    ACI(double b, double i, double f) 
        : Account(b), InterestAccount(b, i), ChargingAccount(b, f) {}

    void transfer(double amount, Account& target) {
        if (amount <= Balance) {
            this->withdraw(amount); 
            target.deposit(amount); 
            cout << "Transfer Successful to Account object." << endl;
        }
    }

    void transfer(double amount, InterestAccount& target) {
        if (amount <= Balance) {
            this->withdraw(amount);
            target.deposit(amount);
            cout << "Transfer Successful to InterestAccount object." << endl;
        }
    }

    void transfer(double amount, ChargingAccount& target) {
        if (amount <= Balance) {
            this->withdraw(amount);
            target.deposit(amount);
            cout << "Transfer Successful to ChargingAccount object." << endl;
        }
    }
};

int main() {
    cout << "--- Setup ACI Account (Source) ---" << endl;
    ACI myAccount(1000, 0.30, 25);

    cout << "\n--- Setup Target Account ---" << endl;
    Account otherAccount(500);

    cout << "\n--- Testing Functionalities ---" << endl;
    myAccount.checkBalance();
    
    myAccount.deposit(100); 
    
    myAccount.withdraw(50);

    cout << "\n--- Testing Transfer ---" << endl;
    myAccount.transfer(200, otherAccount);

    cout << "\nFinal State:" << endl;
    cout << "Source "; myAccount.checkBalance();
    cout << "Target "; otherAccount.checkBalance();

    return 0;
}