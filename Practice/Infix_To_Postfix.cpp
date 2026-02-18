#include <iostream>
#include <stack>
using namespace std;

int precedence (char input)
{
    if (input=='^')
    return 3;
    else if (input == '*'||input == '%'||input == '/')
    return 2;
    else 
    return 1;
}
int main()
{
    string input;
    cout<<"Enter the Infix expression : ";
    cin>>input;

    string postfix ="";

    int counter =0 ;
    stack <char>s;

    for (int i = 0;i<input.size();i++)
    {
        if ((input[i]>='a' && input[i]<='z') || (input[i]>='A' && input[i]<='Z') ||( input[i]>='0' && input[i]<='9'))
        {
            postfix+=input[i];
            counter++;
        }
        else if (input[i]=='(')
        {
            s.push(input[i]);
        }
        else  if (input[i] ==')') 
        {
            while (!s.empty() && s.top() != '(') 
            {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(')
                s.pop(); 

        }
        else 
        {
            int priority = precedence(input[i]);

            while (!s.empty() && precedence(s.top()) >= priority && s.top() != '(')
            {
                postfix += s.top();

                s.pop();
                counter++;
            }
            s.push(input[i]);

        }
    }

    while (!s.empty()) 
    {
        if (s.top() != '(')   
            postfix += s.top();
        s.pop();
    }


    cout<<"The INFIX expression you entered is : ";
    cout<<input<<"\n";
    cout<<"The POSTFIX expression is : ";
    for (char  c : postfix)
    {
        cout << c <<" ";
    }
    cout<<"\n";






}