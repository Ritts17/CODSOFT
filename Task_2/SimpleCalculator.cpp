#include<iostream>
using namespace std;

float Add(float n,float m)
{
    return n+m;
}
float Sub(float n,float m)
{
    return n-m;
}
float Mult(float n, float m)
{
    return n*m;
}
float Div(float n,float m)
{
    return n/m;
}

int main()
{
    float a,b;
    int ch;
    cout<<"--------------Simple Calculator-----------------\n"<<endl;
    cout<<"1)Addition\n2)Substraction\n3)Multiplication\n4)Division\n5)Exit\n"<<endl;
    
    do{
        cout<<"\nEnter your chooice :-";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Enter the numbers:- ";
                cin>>a>>b;
                cout<<"Addition= "<<Add(a,b);
                break;
            case 2:
                cout<<"Enter the numbers:- ";
                cin>>a>>b;
                cout<<"Substraction= "<<Sub(a,b);
                break;
            case 3:
                cout<<"Enter the numbers:- ";
                cin>>a>>b;
                cout<<"Multiplication= "<<Mult(a,b);
                break;
            case 4:
                cout<<"Enter the numbers:- ";
                cin>>a>>b;
                cout<<"Division= "<<Div(a,b);
                break;
            case 5:
                cout<<"Thank you for using our calculator!!!";
                break;
            default:
                cout<<"Wrong chooice.";   
        }
    }while(ch<=4);
    return 0;
}