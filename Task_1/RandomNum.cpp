#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;    

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    int randomNo= rand();
    int Guess;

    cout<<"-----------Welcome to Number Guessing Game!!-------------"<<endl;
    do{
        cout<<"Enter your guess:- ";
        cin>>Guess;
        if(Guess<randomNo)
            cout<<"Sorry! Your guess is too low, best luck next time."<<endl;
        else if(Guess>randomNo)
            cout<<"Sorry! Your guess is too high, best luck next time."<<endl;
        else
            cout<<"Yes, you did it!!!";
    }while(Guess!=randomNo);
return 0;
}