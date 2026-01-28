#include<iostream>
using namespace std;
class BookType{
    string title,publisher,author;
    string*authors;
    int no_copies,price,no_authors;
    long ISBN;
    public:
        BookType(){
            authors=NULL;
        }
        BookType(string t,string p,long ISBN,int copies,int price,int no_authors){
            title=t;
            publisher=p;
            this->ISBN=ISBN;
            no_copies=copies;
            this->price=price;
            this->no_authors=no_authors;
            if (no_authors==1){
                cout<<"Enter the name of the author : ";
                cin>>author;
            }
            else if (no_authors<=4){
                authors=new string[no_authors];
                for (int i=0;i<no_authors;i++){
                    cout<<"Enter name of author "<<i+1<<"  : ";
                    cin>>authors[i];
                    cout<<endl;
                }
            }
            else{
                cout<<"A book can't has more than four authors."<<endl;
                return ;
            }
        }
        void set_title(string title){
            this->title=title;
        }
        
        void show_title(){
            cout<<"The title of the book is : "<<title<<endl;
        }
        
        void set_publisher(string publisher){
            this->publisher=publisher;
        }
        
        void show_publisher(){
            cout<<"The publisher of the book is :"<<publisher<<endl;
        }
        
        void set_author(int n){
            no_authors=n;
            if (n==1){
                cout<<"Enter the name of the author : ";
                cin>>author;
            }
            else if (n<=4){
                authors=new string[n];
                for (int i=0;i<n;i++){
                    cout<<"Enter name of author "<<i+1<<"  : ";
                    cin>>authors[i];
                    cout<<endl;
                }
            }
            else{
                cout<<"A book can't has more than four authors."<<endl;
                return ;
            }
        }
        
        void show_author(){
            if (no_authors==1){
                cout<<"The name of the author of the book is : "<<author<<endl;
            }
            else if (no_authors>1){
                cout<<"The authors of the book are : ";
                for(int i=0;i<no_authors;i++){
                    if(i<no_authors-1){
                        cout<<authors[i]<<" , ";
                    }
                    else{
                        cout<<authors[i];
                    }
                }
            }
        }
        
        void set_ISBN(long ISBN){
            this->ISBN=ISBN;
        }
        
        void show_ISBN(){
            cout<<"The ISBN of the book is : "<<ISBN<<endl;
        }
        
        void set_copies(int num){
            no_copies=num;
        }
        
        void show_copies(){
            cout<<"The copies of the book is : "<<no_copies<<endl;
        }
        
        void update_copies(int n){
            no_copies+=n;
        }
        
        void return_copies(int n){
            no_copies-=n;
        }
        
        
        void set_bookprice(int price){
            this->price=price;
        }
        void show_bookprice(){
            cout<<"The price of the book is : Rs."<<price<<endl;
        }
        
        ~BookType(){
            delete authors;
        }
        
        
    
    
};
int main(){
    BookType lib[2];
    string title,publisher;
    int no_copies,price,no_authors;
    long ISBN;
    
    for (int i=0;i<2;i++){
        cout<<"-----------Details of book "<<i+1<<"------------"<<endl;
        cout<<"Enter the title of the book : ";
        cin>>title;
        lib[i].set_title(title);
        
        cout<<"Enter the number of authors of the book : ";
        cin>>no_authors;
        lib[i].set_author(no_authors);
        
        cout<<"Enter the name of the publisher : ";
        cin>>publisher;
        lib[i].set_publisher(publisher);
        
        cout<<"Enter the ISBN : ";
        cin>>ISBN;
        lib[i].set_ISBN(ISBN);
        
        cout<<"Enter the number of copies in stock : ";
        cin>>no_copies;
        lib[i].set_copies(no_copies);
        
        cout<<"Enter the price of the book : Rs.";
        cin>>price;
        lib[i].set_bookprice(price);
        
    }
    
    for (int i=0;i<2;i++){
        cout<<"-----------Details of book "<<i+1<<"------------"<<endl;
        
        lib[i].show_title();
        lib[i].show_author();
        lib[i].show_publisher();
        lib[i].show_ISBN();
        lib[i].show_copies();
        lib[i].show_bookprice();
        
    }
    
    
    
    
    return 0;
}