#include<iostream>
using namespace std;
class DynamicArray{
  int *ptr;
  int size,temp;
  public:
  
    DynamicArray() : size(0),ptr(NULL) {}
    DynamicArray(int size){
      this->size=size;
      ptr=new int [size];
      temp=size;
      for(int i=0;i<size;i++){
        ptr[i]=0;
      }
    }
    
    void push(int num){
      ptr[temp-1]=num;
      temp-=1;
    }
    
    void get_size(){
      cout<<"The size of the array is : "<<size<<endl;
    }
    
    void get_array(){
      cout<<"[";
      for (int i=0;i<size;i++){
        if(i<size-1){
        cout<<ptr[i]<<" ,";
      }
        else{
          cout<<ptr[i];
        }
      }
      cout<<"]"<<endl;
    }
};

int main(){
  DynamicArray obj(5);
  obj.push(4);
  obj.push(8);
  obj.push(5);
  obj.push(9);
  obj.push(2);
  obj.get_size();
  obj.get_array();
  
  return 0;
}