#include <iostream>
#include <stack>
using namespace std;
int main ()
{
    stack <char> s ;
    string expression ;
    cout<<"Enter the expression : ";
    cin>>expression;
    bool valid_expression=true;
    for (int i = 0; i<expression.size();i++)
    {
        if (expression[i]=='('||expression[i]=='['||expression[i]=='{')
        {
            s.push(expression[i]);
        }
        else if (expression[i]==')')
        {
            if (s.empty()) 
            {
                valid_expression = false;
                break;
            }
            if (s.top()=='(')
            {
                s.pop();
            }
            else
            {
                valid_expression=false;
                break;
            }
        }
        else if (expression[i]==']')
        {
            if (s.empty()) 
            {
                valid_expression = false;
                break;
            }
            if (s.top()=='[')
            {
                s.pop();
            }
            else
            {
                valid_expression=false;
                break;
            }
        }
        else if (expression[i]=='}')
        {
            if (s.empty()) 
            {
                valid_expression = false;
                break;
            }
            if (s.top()=='{')
            {
                s.pop();
            }
            else
            {
                valid_expression=false;
                break;
            }
        }



    }
    valid_expression=(!s.empty()) ? false : true;
    
    string ans=(valid_expression)? " Is valid !" : " Is not valid ";
    cout<<"The expression you entered : "<<expression << ans <<" \n";
    return 0;
}