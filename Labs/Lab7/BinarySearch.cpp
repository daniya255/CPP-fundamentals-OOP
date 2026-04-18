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

bool CheckMatrix( const Array2D& matrix,int m,int n,int target ){
    if(m==0 || n==0)
        return false;
    
    int low=0;
    int high=(m*n)-1;
    
    while(low<=high){
        int mid=low + (high-low)/2;
        int row=mid/n;
        int col=mid%n;
        
        int mid_ind=matrix[row][col];
        
        if(mid_ind==target){
            return true;}
        else if (mid_ind<target){
            low=mid+1;}
        else{
            high=mid-1;}
    }
    return false;
}
int main() 
{
    int m,n,target;
    
    cout<<"Enter number of rows and columns : ";
    cin>>m>>n;
    Array2D matrix(m,n);
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<"Enter element at index ["<<i<<"]["<<j<<"] : ";
            cin>>matrix[i][j];
            cout<<endl;
        }
    }
   
    cout<<"Enter your target here : ";
    cin>>target;
    
    cout<<"The result of the searching is : "<<CheckMatrix(matrix,m,n,target)<<endl;
   
    
    return 0;
}