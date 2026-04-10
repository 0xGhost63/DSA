/*

    NAME: SANNAN AHMAD
    ROLL # SP25-BSE-118
*/

//  NOTE :  0 is used to indicate the empty indices !

#include<iostream>
#define SIZE 5
using namespace std;

class Stack
{
    public:

    int top;
    int arr [SIZE];

    //HERE IM MAKING CONSTRUCTOR OF THE STACK CLASS TO INTITALIZE THE TOP
    Stack()
    {
        top=-1;
    }

    //METHOD TO PUT THE ELEMENTS IN THE ARRAY (QUEUE)
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

    //METHOD TO REMOVE THE ELEMENTS IN THE ARRAY (QUEUE)
    //HERE I HAVE MADE IT OF THE RETURN TYPE INT TO SAVE THE POPPED ELEMENT !
    int pop()
    {
        if (top==-1)
        {
            cout<<"Stack is empty already,nothing to delete here !\n";
            return -1;
        }
        else
        {
            int temp=arr[top];
            arr[top]=0;
            top--;   
            return temp;
        }
    }



};


class Queue
{
    public:

    int front,rear;
    int arr[5]={0};//HERE I M SHOWING THE EMPTY ELEMENTS AS 0S

    //CONSTUCTOR FOR THE QUEUE CLASS FOR INITIALZATION PURPOSES !
    Queue()
    {
        front=-1;
        rear=-1;
    }

    // METHOD TO CHECK WHETHER QUEUE IS EMPTY OR NOT
    bool isEmpty()
    {
        return (front==-1 && rear==-1);
    }


    void enqueue(int value)
    {
        //Empty State
        if (isEmpty())
        {
            front++;
            rear++;
            arr[rear]=value;
        }
        //Full State
        else  if (rear==SIZE-1)
        {
            cout<<"Queue overflow :( \n";
        }
        //Normal State
        else 
        {
            rear++;
            arr[rear]=value;
        }

    }

    int  dequeue()
    {
        //Empty State
        if (isEmpty())
        {
            cout<<"Queue is empty,can't delete the element !\n";
            return -1;
        }
        //Full State
        else if (rear==front)
        {
            int temp=arr[front];
            arr[front]=0;
            rear=-1;
            front=-1;
            return temp;
        }
        //Normal State
        else
        {
            int temp=arr[front];
            arr[front]=0;
            front++;
            return temp;
        }

    }

    // METHOD TO PRINT THE ELEMENTS OF THE QUEUE
    void currentState()
    {
        cout<<"THE CURRENT STATE OF THE QUEUE IS : ";
        for (int i : arr)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }

};

int main()
{
    Queue q;
    Stack s;


    for (int i=0;i<SIZE;i++)
    {
        int temp=0;
        cout<<"Enter element # "<<i+1<<" >>> ";
        cin>>temp;
        q.enqueue(temp);
    }
     
    cout<<"\nBEFORE REVERSING !\n";
    q.currentState();

    for (int i =0;i<SIZE;i++)
    {
        int temp=q.dequeue();
        if(temp!=-1)
        {
            s.push(temp);
        }
    }

    for (int i=0;i<SIZE;i++)
    {
        int temp=s.pop();
        if (temp!=-1)
        {
            q.enqueue(temp);
        }
    }
    cout<<"\nAFTER REVERSING : \n";
    q.currentState();

    cout<<"/nFIN...THANK YOU FOR USING THE PROGRAM :)\n";
    return 0;
}



