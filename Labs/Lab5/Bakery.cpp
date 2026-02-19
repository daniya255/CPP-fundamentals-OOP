#include <iostream>
using namespace std;
class Item{
  protected:
    string name;
    int quantity;
public:
    void set_item(string name,int quantity){
       this->name=name;
       this->quantity=quantity;
    }
};
class BakedGoods: public Item{
    protected:
        float discount=0.1;
    
};
class Cakes: public BakedGoods{
    private:
        int price=600;
    public:
        float get_bill(){
            float total=price*quantity;
            total=total-(total*discount);
            return total;
        }
};
class Bread: public BakedGoods{
    protected:
        int price=200;
    public:
        float get_bill(){
            float total=price*quantity;
            total=total-(total*discount);
            return total;
        }
};
class Drinks: public Item{
    protected:
        float discount=0.05;
        int price =100;
     public:
        float get_bill(){
            float total=price*quantity;
            total=total-(total*discount);
            return total;
        }
};
int main() {
    cout<<"Select the items from the following list: "<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"1.Cakes : price-Rs.600"<<endl;
    cout<<"2.Bread : price-Rs.200"<<endl;
    cout<<"3.Drinks : price-Rs.100"<<endl;
    cout<<"--------------------------------------"<<endl;
    
    int choice;
    cout<<"Enter your choice : ";
    cin>>choice;
    
 if(choice==1){
     Cakes cake;
     cake.set_item("cake",3);
     float bill=cake.get_bill();
     cout<<"Bill: Rs."<<bill<<endl;
 }
 else if(choice==2){
     Bread bread;
     bread.set_item("breaD",2);
     float bill=bread.get_bill();
     cout<<"Bill: Rs."<<bill<<endl;
 }
 else if(choice==3){
     Drinks drink;
     drink.set_item("drinks",5);
     float bill=drink.get_bill();
     cout<<"Bill: Rs."<<bill<<endl;
 }
 else {
     cout<<"Enter a valid choice"<<endl;
 }

    

    return 0;
}