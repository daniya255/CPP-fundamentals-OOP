#include <iostream>
using namespace std;
class Weapons{
    public:
        void WeaponsDescription(){
            cout<<"Weapons are used for destruction"<<endl;
        }
};
class HotWeapons: public Weapons{
     public:
        void HotWeaponsDescription(){
            cout<<"Hot Weapons  used  gunpowder and explode"<<endl;
        }
};
class Bombs: public HotWeapons{
     public:
        void BombsDescription(){
            cout<<"Bombs blow up "<<endl;
        }
};
class NuclearBombs: public Bombs{
     public:
        void NuclearBombsDescription(){
            cout<<"Nuclear bombs used nuclear fission and fusion."<<endl;
        }
};
int main() {
    
    NuclearBombs nb;
    nb.WeaponsDescription();
    nb.HotWeaponsDescription();
    nb.BombsDescription();
    nb.NuclearBombsDescription();

    return 0;
}