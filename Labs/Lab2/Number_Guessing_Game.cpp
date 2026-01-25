#include<iostream>
#include<cstdlib>
#include <ctime>
using namespace std;
class Game{
    int team_members;
    int your_score;
    int enemy_score;
    
    public:
        Game(){
            srand(time(0));
            team_members=rand()%5 +1;
            your_score=0;
            enemy_score=0;
       
        }
    
        void start(){
            cout<<"Total number of players in your team are : "<<team_members<<endl;
           
            for(int i=0;i<team_members;i++){
                 cout<<"----------Round"<<i+1<<"-----------"<<endl;
                 int num1=rand()%10 +1;
                 int num2=rand()%10 +1;
                 cout<<"The pair of numbers generated are below"<<endl;
                 cout<<"Number 1 : "<<num1<<endl;
                 cout<<"Number 2 : "<<num2<<endl;
                 if (num1==num2){
                     cout<<"Enemy got hit by your team!"<<endl;
                     your_score+=1;
                 }
                 else{
                     cout<<"You got hit by your enemy team!"<<endl;
                         enemy_score+=1;
                }
            }
            cout<<"Game over !!!"<<endl;
            
            if (your_score<enemy_score){
                cout<<"Your enemy team has won the game.."<<endl<<"Better luck next time"<<endl;
            }
            else if (your_score==enemy_score){
                cout<<"It is a tie between your and enemy team."<<endl;
            }
            else{
                cout<<"You won this game!"<<endl<<"Congratulations"<<endl;
            }
    }
    
};        

int main(){
    Game game;
    game.start();
    return 0;
}