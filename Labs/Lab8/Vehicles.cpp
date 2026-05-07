#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string type; 
    string make;
    string model;
    string color;
    int year;
    double milesDriven;

public:
    Vehicle(string t, string mk, string md, string c, int y, double miles): type(t), make(mk), model(md), color(c), year(y), milesDriven(miles) {}
    string get_type() const{ return type;}
    string get_make() const{ return make;}
    string get_model() const{ return model;}
    string get_color() const{ return color;}
    int get_year() const{ return year;}
    double get_milesDriven() const{ return milesDriven;}
    virtual ~Vehicle() {}
};


class GasVehicle : virtual public Vehicle {
protected:
    double fuelTankSize;

public:
    GasVehicle(string t, string mk, string md, string c, int y, double miles, double tank): Vehicle(t, mk, md, c, y, miles), fuelTankSize(tank) {}
    double getTankSize() const { return fuelTankSize; }
  
};


class ElectricVehicle : virtual public Vehicle {
protected:
    double energyStorage;

public:
    ElectricVehicle(string t, string mk, string md, string c, int y, double miles, double energy): Vehicle(t, mk, md, c, y, miles), energyStorage(energy) {}
    double getEnergyStorage() const { return energyStorage; }
};

class HighPerformance : public GasVehicle {
protected:
    int horsePower;
    double topSpeed;

public:
    HighPerformance(string t, string mk, string md, string c, int y, double miles, double tank, int hp, double speed) : Vehicle(t, mk, md, c, y, miles), GasVehicle(t, mk, md, c, y, miles, tank), horsePower(hp), topSpeed(speed) {}
    int get_hp() const{ return horsePower; }
    double get_topSpeed() const { return topSpeed; }
  
};

class HeavyVehicle : public GasVehicle, public ElectricVehicle {
protected:
    double maxWeight;
    int numWheels;
    double length;

public:
    HeavyVehicle(string t, string mk, string md, string c, int y, double miles, double tank, double energy, double weight, int wheels, double len): Vehicle(t, mk, md, c, y, miles), 
          GasVehicle(t, mk, md, c, y, miles, tank), ElectricVehicle(t, mk, md, c, y, miles, energy), maxWeight(weight), numWheels(wheels), length(len) {}
           double getMaxWeight() const { return maxWeight; }
           int getWheels() const { return numWheels; }
           double getLength() const { return length; }
};

class SportsCar : public HighPerformance {
public:
    string gearbox;    
    string driveSystem; 

    SportsCar(string t,string mk, string md, string c, int y, double miles, double tank, int hp, double speed, string gb, string ds): Vehicle(t, mk, md, c, y, miles),
    HighPerformance(t, mk, md, c, y, miles, tank, hp, speed), gearbox(gb), driveSystem(ds) {}
    string get_gearbox() const{ return gearbox;}
    string get_driveSystem() const{ return driveSystem; }
  
};


class ConstructionTruck : public HeavyVehicle {
public:
    string cargo; 

    ConstructionTruck(string t,string mk, string md, string c, int y, double miles, double tank, double energy, double weight, int wheels, double len, string crg): Vehicle(t, mk, md, c, y, miles),
          HeavyVehicle(t, mk, md, c, y, miles, tank, energy, weight, wheels, len), cargo(crg) {}

    string get_cargo() const { return cargo; }
};


class Bus : public HeavyVehicle {
private:
    int numSeats;

public:
    Bus(string t, string mk, string md, string c, int y, double miles, double tank, double energy, double weight, int wheels, double len, int seats): Vehicle(t, mk, md, c, y, miles),
          HeavyVehicle(t, mk, md, c, y, miles, tank, energy, weight, wheels, len), numSeats(seats) {}

  int get_seats () const { return numSeats; }
};

int main() {
   
   Bus bus("Transit", "Volvo", "9700", "Blue", 2023, 12500.5, 100.0, 400.0, 35000.0, 6, 45.0, 55);
   cout<<"Type:  "<<bus.get_type()<<endl;
   cout<<"Make :  "<<bus.get_make()<<endl;
   cout<<"Model :  "<<bus.get_model()<<endl;
   cout<<"Color :  "<<bus.get_color()<<endl;
   cout<<"Year :  "<<bus.get_year()<<endl;
   cout<<"Miles Driven :  "<<bus.get_milesDriven()<<endl;
   cout<<"Tank Size :  "<<bus.getTankSize()<<endl;
  cout<<"Max Weight "<< bus.getMaxWeight()<<endl;
   cout<<"Length "<<bus.getLength()<<endl;
   cout<<"Seats "<<bus.get_seats()<<endl;
    return 0;
}