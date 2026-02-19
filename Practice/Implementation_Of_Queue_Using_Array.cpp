#include <iostream>
using namespace std;
# define SIZE 8

class Queue
{
    public:

    int r=-1;
    int f=-1;
    int Q [SIZE];

    //Insertion 

    void push(int value)
    {
        if (r==-1 && f==-1)
        {
            r++;
            f++;
            Q[r]=value;
        }
        else if (f==(r+1)%SIZE)
        {
            cout<<"Queue is overflowing...can't add the value "<<value<<endl;
        }
        else
        {
            r=(r+1)%SIZE;
            Q[r]=value;
        }
    }

    //Deletion

    void pop()
    {
        if (r==-1 && f==-1)
        {
            cout<<"Stack is already empty...queue underflow !\n";
        }
        else if (r==f)
        {
            Q[f]=0;
            r=-1;
            f=-1;
        }
        else
        {
            Q[f]=0;
            f=(f+1)  % SIZE;
        }
    }

    //Display
    void display()
    {
        if (f==-1 && r==-1)
        {
            cout<<"Queue is empty !"<<endl;
        }
        else
        {
            cout<<"Queue elements : ";
            int i=f;
            while(true)
            {
                cout<<Q[i]<<" ";
                if(i==r)
                    break;
                i=(i+1)%SIZE;
            }
            cout<<endl;
        }
    }

};

void showMenu()
{
    cout<<"================================\n";
    cout<<"1-Push\n";
    cout<<"2-Pop\n";
    cout<<"0-Exit\n";
    cout<<"================================\n";
}

int main()
{
    Queue q;
    int choice,value;

    do
    {
        showMenu();
        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter value to push : ";
                cin>>value;
                q.push(value);
                q.display();
                break;
            case 2:
                q.pop();
                q.display();
                break;
            case 0:
                cout<<"Exiting...\n";
                break;
            default:
                cout<<"Invalid choice !"<<endl;
        }

    }while(choice!=0);

}
