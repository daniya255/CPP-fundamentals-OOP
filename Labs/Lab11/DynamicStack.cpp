#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;
class DyStack{
    private:
        vector<char>stack;
    public:
void clear() {
    stack.clear();
}
    bool isempty() const {
            return stack.empty();
        }
       void push(char msg){
            stack.push_back(msg);
        }
        void pop(){
            if(!stack.empty()){
                stack.pop_back();
            }
        }
        char peek(){
            if(!stack.empty()){
                return stack.back();
            }
            return '\0';
        }
        
        string reverse(string sentence){
            stack.clear();
            string result="";
            stringstream ss(sentence);
            string word;
            
            while(ss>>word){
                for (char c : word){
                    push(c);
                }
              while(!isempty()){
                  result+=peek();
                  pop();
              }
                result+=" ";
            }
          
        
        if (!result.empty()) {
            result.pop_back();
        }

        return result;
        }
};

int main(){
    DyStack d;
    d.push('s');
    d.push('t');
    d.push('o');
    d.pop();
   cout<<d.peek()<<endl;
   cout<<d.reverse("I am very sad")<<endl;
}