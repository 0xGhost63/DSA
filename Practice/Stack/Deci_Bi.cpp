#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int value;

    

    stack <int> s;

    do 
    {
        cout<<"Enter the value for Deci-->Binary : ";
        cin>>value;
        
        if(value<=0)
        {
            cout<<"Enter an unsigned value Plz ! \n";
        }


    }while(value<=0);

    int original_value=value;
    while (value>0)
    {
        int rem;
        rem=value%2;
        value=value/2;
        s.push(rem);
    }

    cout<<"The binary value of the , "<<original_value<<" is : ";

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}