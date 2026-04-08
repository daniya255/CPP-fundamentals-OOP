#include <iostream>
using namespace std;
#include <string>

class Position {
public:
    int x, y;

    Position(int x = 0, int y = 0) : x(x), y(y) {}

    Position operator+(const Position& p) const {
        return Position(x + p.x, y + p.y);
    }

    void display() const {
        cout << "(" << x << ", " << y << ")" <<endl;
    }
};
class Character {
public:
    virtual void attack() = 0; 
    virtual void power() = 0;
    
    virtual ~Character() {}       
};


class Warrior : public Character {
public:
    void attack() const override {
        cout << "Warrior swings a heavy Greatsword!" <<endl;
    }
    void power() const override {
        cout << "Warrior uses 'Berserker Rage' - Defense down, Attack up!" <<endl;
    }
};


class Mage : public Character {
public:
    void attack() const override {
        cout << "Mage casts a Magic Missile!" <<endl;
    }
    void power() const override {
        cout << "Mage uses 'Arcane Surge' - Massive AOE damage!" <<endl;
    }
};

class DamageCalculator {
public:
    
    void calculateDamage(int baseDmg) {
        cout << "Calculating Basic Damage: " << baseDmg <<endl;
    }

    
    void calculateDamage(int baseDmg, double multiplier) {
        cout << "Calculating Special Damage: " << (baseDmg * multiplier) <<endl;
    }
};

int main() {
  
    Character* hero1 = new Warrior();
    Character* hero2 = new Mage();

    hero1->attack();
    hero1->power();
    
    hero2->attack();
    hero2->power();
    
    DamageCalculator dc;
    dc.calculateDamage(50);             
    dc.calculateDamage(50, 1.5);        

    Position p1(10, 20);
    Position p2(5, 5);
    Position p3 = p1 + p2; 

    std::cout << "Initial Position: "; p1.display();
    std::cout << "Movement Vector: "; p2.display();
    std::cout << "New Position:     "; p3.display();

    
    delete hero1;
    delete hero2;

    return 0;
}