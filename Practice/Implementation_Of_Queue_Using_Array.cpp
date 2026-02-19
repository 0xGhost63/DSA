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
        else if (f!=0)
        {
            r=0;
            Q[r]=value;
        }
        else
        {
            r++;
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
    else if (f==SIZE || f==(f+1)%SIZE)
    {
        Q[f]=0;
        f=0;
    }
    else
    {
        Q[f]=0;
        f++;   
    }
}
};
int main()
{

}