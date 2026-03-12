#include <iostream>
#include <stack>

using namespace std;
int main()
{

    string str;
    stack <char> Stack;
    cout<<"Enter the string : ";
    cin>>str;

    for (int i=0;i<str.size();i++)
    {
        Stack.push(str[i]);
    }

    cout<<"The mirror string is : ";
    while (!Stack.empty())
    {
        char temp;
        temp=Stack.top();
        Stack.pop();
        cout<<temp;
    }
    cout<<"\n";
}