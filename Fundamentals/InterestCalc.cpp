#include<iostream>
using namespace std;
class BankDeposit{
    int year;
    int principal;
    float interest_rate;
    float return_amount;

    public:
        BankDeposit(){}
        BankDeposit(int p,int y,float i){
            interest_rate=i;
            year=y;
            principal=p;
            return_amount=principal;
            for(int i=0;i<y;i++){
                return_amount=return_amount*(1+interest_rate);
            }
        }
        BankDeposit(int p,int y,int i){
            interest_rate=float(i)/100;
            year=y;
            principal=p;
            return_amount=principal;
            for(int i=0;i<y;i++){
                return_amount=return_amount*(1+interest_rate);
            }
        }

        void show(){
            if(year>1)
                cout<<"Your initial principal amount is Rs."<<principal<<endl<<"Your return amount after "<<year<<" years is Rs."<<return_amount<<" with interest rate "<<interest_rate<<endl;
            else
                cout<<"Your initial principal amount is Rs."<<principal<<endl<<"Your return amount after "<<year<<" years is Rs."<<return_amount<<" with interest rate "<<interest_rate<<endl;

        }


};
int main(){

    int y,p,i;
    cout<<"Enter principal amount, interest rate and years below. "<<endl;
    cin>>p>>i>>y;

    BankDeposit d1(p,y,i);
    d1.show();

    int yr,ip;
    float r;
    cout<<"Enter principal amount, interest rate and years below. "<<endl;
    cin>>ip>>r>>yr;

    if(y<=0){
        cout<<"Enter valid years starting from 1."<<endl;
        return 0;
    }

    BankDeposit d2(ip,yr,r);
    d2.show();

 return 0;
}