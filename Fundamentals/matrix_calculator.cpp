#include <iostream>
using namespace std;
void add(int arr[3][3],int brr[3][3],int result[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            result[i][j]=arr[i][j]+brr[i][j];
        }
    }

}

void print(int arr[3][3]){
    cout<<"Adding the matrices"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

void multiply(int arr[3][3],int brr[3][3],int result[3][3]){
    cout<<"Multiplying the matrices."<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
             result[i][j]=0;
            for(int k=0;k<3;k++){
                result[i][j]+=arr[i][k]*brr[k][j];
            } 
        }
    }
}
int main(){
    int m1[3][3];
    int m2[3][3];

    cout<<"For matrix one"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<"Enter element at "<<i<<" "<<j<<" : ";
            cin>>m1[i][j];
            cout<<endl;

        }
    }

    cout<<"For matrix two"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<"Enter element at "<<i<<" "<<j<<" : ";
            cin>>m2[i][j];
            cout<<endl;

        }
    }

    int m3[3][3],m4[3][3];

    int ch;

    cout<<"This program can perform two operations i.e, addition and multiplication."<<endl;
    cout<<"Enter the operation you want to perform on your matrices."<<endl<<"1.Addition"<<endl<<"2.Multiplication"<<endl;
    cout<<"Enter your response : ";
    cin>>ch;
    cout<<endl;

    if (ch==1){
        add(m1,m2,m3);
        print(m3);
    }
    else if(ch==2){
        multiply(m1,m2,m3);
        print(m3);
    }
    else
        cout<<"Invalid input entered"<<endl;

    return 0;
}