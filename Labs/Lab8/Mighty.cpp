#include <iostream>
#include <string>
using namespace std;
class Character {
protected:
    string name;
    int level;
    int health;

public:
    Character(string n, int l, int h) : name(n), level(l), health(h) {}
    virtual ~Character() {}
    
    string getName() const { return name; }
    int getLevel() const { return level; }
    int getHealth() const { return health; }

    virtual void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Health: " << health << endl;
    }
};



class Warrior : virtual public Character {
protected:
    int strength;
    string weaponProficiency;

public:
    Warrior(string n, int l, int h, int str, string wp)
        : Character(n, l, h), strength(str), weaponProficiency(wp) {}

    void slash() const {
        cout << name << " performs a powerful slash ability!" << endl;
    }
};

class Mage : virtual public Character {
protected:
    int intelligence;
    int spellProficiency;

public:
    Mage(string n, int l, int h, int intel, int spellProf)
        : Character(n, l, h), intelligence(intel), spellProficiency(spellProf) {}

    void fireball() const {
        cout << name << " casts a fireball ability!" << endl;
    }
};

class Archer : virtual public Character {
protected:
    int dexterity;

public:
    Archer(string n, int l, int h, int dex)
        : Character(n, l, h), dexterity(dex) {}

    void rapidShot() const {
        cout << name << " performs a rapid shot ability!" << endl;
    }
};

class NPC : public Character {
private:
    string movementPattern;

public:
    NPC(string n, int l, int h, string move)
        : Character(n, l, h), movementPattern(move) {}

    void speak() const {
        cout << name << " says: 'Welcome to the village!'" << endl;
    }
};



class Mighty : public Warrior, public Mage {
public:
    Mighty(string n, int l, int h, int str, string wp, int intel, int spellProf)
        : Character(n, l, h), 
          Warrior(n, l, h, str, wp), 
          Mage(n, l, h, intel, spellProf) {}

    void displayMighty() const {
        displayInfo();
        slash();
        fireball();
    }
};


int main() {

    Mighty hero("Arthor the Wise", 50, 1000, 85, "Greatsword", 90, 100);

    cout << "--- Character Sheet: Mighty ---" << endl;
    hero.displayMighty();
    cout<<endl;

    cout << "--- NPC Interaction ---" << endl;
    NPC villager("Old Man Jenkins", 1, 50, "Stationary");
    villager.displayInfo();
    villager.speak();

    return 0;
}