#include <iostream>
#include <cstdlib>
using namespace std;
class Array2D{
  private:
  int rows,cols;
    int **ptr;
  public:
    Array2D(int r=0,int c=0): rows(r),cols(c),ptr(NULL) {
      if (cols>0 && rows>0){
        ptr=new int *[rows];
        for (int i=0;i<rows;i++){
          ptr[i]=new int [cols];
        }
      }
      if (ptr==NULL){
        exit(1);
      }
    }
    Array2D(Array2D & obj){
      if(obj.rows>0 && obj.cols>0){
        rows=obj.rows;
        cols=obj.cols;
        ptr=new int *[rows];
        for(int i=0;i<rows;i++){
          ptr[i]=new int [cols];
        }
        if(ptr==NULL){
          exit(1);
        }
        
        for(int i=0;i<rows;i++){
          for(int j=0;j<cols;j++){
            ptr[i][j]=obj[i][j];
          }
        }
      }
      else{
        exit(1);
      }
    }
    
  int* operator [](int index) const{
    if(index>=rows){
  cout<<"index "<<index<<" is out of bound"<<endl;
  exit(1);
}
    return ptr[index];
  }
  
   Array2D operator +(const Array2D& obj){
    if (rows==obj.rows && cols==obj.cols){
      Array2D temp(rows,cols);
      for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
          temp[i][j]=ptr[i][j]+obj[i][j];
        }
      }
      
       return temp;
    }
    else{
      cout<<"Both matrices should be of equal size for addition"<<endl;
      exit(1);
    }
    
  }
  
  Array2D operator -(const Array2D& obj){
    if (rows==obj.rows && cols==obj.cols){
      Array2D temp(rows,cols);
      
      for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
          temp[i][j]=ptr[i][j]-obj[i][j];
        }
      }
      
       return temp;
    }
    else{
      cout<<"Both matrices should be of equal size for subtraction"<<endl;
      exit(1);
    }
    
  }
  
  Array2D operator *(const Array2D& obj){
    if(cols!=obj.rows){
      cout<<"Multiplication isnot possible"<<endl;
      exit(1);
    }
    Array2D temp(rows,obj.cols);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
          temp[i][j]=0;
          for(int k=0;k<cols;k++){
            temp[i][j]+=ptr[i][k]*obj[k][j];
          }
        }
      }
      return temp;
  }
  
  Array2D operator =(const Array2D& obj){
    
    if(this==&obj){
      return *this;
    }
    
   if(ptr!=nullptr){
      for(int i=0;i<rows;i++){
        delete [] ptr[i];
      }
      
      delete [] ptr;
    }
    
    rows=obj.rows;
    cols=obj.cols;
    
    if (rows > 0 && cols > 0) {
        ptr = new int*[rows];
        for (int i = 0; i < rows; i++) {
            ptr[i] = new int[cols];
            
            for (int j = 0; j < cols; j++) {
                ptr[i][j] = obj.ptr[i][j];
            }
        }
    }
    else {
        ptr = nullptr;
    }
    
    return *this;
    
  }
  
  ~Array2D(){
    if(ptr!=nullptr){
      for(int i=0;i<rows;i++){
        delete [] ptr[i];
      }
    }
    delete [] ptr;
  }
      
};
int main() 
{
    Array2D matrix1(2,3), matrix2(3,2);
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            matrix1[i][j]=j+5;
            matrix2[i][j]=j*2;
        }
    }
    Array2D sum=matrix1*matrix2;
    cout<<"Result of multiplication of two matrices."<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }
    
    Array2D matrix3=matrix1;
    cout<<"The matrix made by copy constructor"<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            cout<<matrix3[i][j]<<" ";
        }
        cout<<endl;
    }
    
    Array2D 
    
    return 0;
}