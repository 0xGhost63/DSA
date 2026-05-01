#include <iostream>
#define SIZE 5
using namespace std;


class Stack
{
    public:

    int top;
    int arr [SIZE];

    Stack()
    {
        top=-1;
    }

    void push(int value)
    {
        if (top==SIZE-1)
        {
            cout<<"STACK OVERFLOW\n";
        }
        else 
        {
            top++;
            arr[top]=value;
        }
    }

    void pop()
    {
        if (top==-1)
        {
            cout<<"Stack is empty already\n";
        }
        else
        {
            arr[top]=0;
            top--;
            
        }
    }

    int peek()
    {
        if (top==-1)
        {
            cout<<"Stack is empty\n";
            return 0;
        }
        else
        {
            return arr[top];
        }
    }
    void printStack(Stack stack)
    {
        while(stack.top!=-1)
        {
            cout<<arr[stack.top]<<" ";
            stack.top--;
        }
    }


};

int main()
{
    Stack s;
    s.push(3);
    s.push(2);
    s.push(1);
    s.printStack(s);
    s.pop();
}