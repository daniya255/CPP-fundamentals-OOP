#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vehicle {
protected:
    string carId;
    string brand;
    string model;
public:
    Vehicle(string id, string b, string m) : carId(id), brand(b), model(m) {}
    virtual bool isAvailable() = 0;
    virtual void rent() = 0;
    virtual void returnVehicle() = 0;
    virtual string getDetails() { return brand + " " + model + " (" + carId + ")"; }
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
private:
    bool available;
public:
    Car(string id, string b, string m) : Vehicle(id, b, m), available(true) {}

    bool isAvailable() override {
        return available;
    }

    void rent() override {
        available = false;
    }

    void returnVehicle() override {
        available = true;
    }
};

class RentalSystem {
public:
    void rentVehicle(Vehicle* v) {
        if (v->isAvailable()) {
            v->rent();
            cout << "Successfully rented: " << v->getDetails() << endl;
        } else {
            cout << "Vehicle " << v->getDetails() << " is currently not available." << endl;
        }
    }

    void returnVehicle(Vehicle* v) {
        v->returnVehicle();
        cout << "Successfully returned: " << v->getDetails() << endl;
    }
};

class Customer {
private:
    string name;
public:
    Customer(string n) : name(n) {}

    void rentVehicle(RentalSystem& system, Vehicle* v) {
        cout << "Customer " << name << " is attempting to rent..." << endl;
        system.rentVehicle(v);
    }

    void returnVehicle(RentalSystem& system, Vehicle* v) {
        cout << "Customer " << name << " is returning the vehicle..." << endl;
        system.returnVehicle(v);
    }
};

int main() {
    RentalSystem agency;
    Customer user("Alice");

    Car* car1 = new Car("C101", "Toyota", "Corolla");
    Car* car2 = new Car("C102", "Honda", "Civic");

    user.rentVehicle(agency, car1);
    user.rentVehicle(agency, car1); // Attempt to rent same car again
    user.returnVehicle(agency, car1);
    user.rentVehicle(agency, car2);

    delete car1;
    delete car2;

    return 0;
}