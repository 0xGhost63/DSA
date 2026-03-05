#include <iostream>
using namespace std;
#define size 5
class Stack
{
    public :
        int top=-1;

        //SIZE OF THE STACK IS BEING USED HERE 

        int arr [size]={0};

        bool isEmpty()
        {
            return top==-1;
        }
        void push(int value)
        {
            if (top==size-1)
            {
                cout<<"Stack Overflow !!\n";
            }
            else
            {
                top++;
                arr[top]=value;
            }
        }

        int peek()
        {
            if (!(top==-1))
            {
                return arr[top];
            }
            else
            {
                cout<<"Stack is empty !\n";
                return -1 ;
            }
        }

        int pop ()
        {
            if (!(top==-1))
            {
                int temp;
                temp=arr[top];
                arr[top]=0;
                top--;
                return temp;
            }
            else
            {
                cout<<"Stack is already empty !\n";
                return 0;
            }
        }

        void current_state()
        {
            for (int i =0 ;i <size;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
        }

    private:

};

void printMenu()
{
    cout<<"======================\n";
    cout<<"The available options are : "<<endl;
    cout<<"1-Push\n";
    cout<<"2-Pop\n";
    cout<<"3-Peek\n";
    cout<<"4-isEmpty\n";
    cout<<"0-EXIT\n";
    cout<<"======================\n";
}

int main ()
{
    Stack s1;

    int choice ;

    while (!(choice==0))
    {
        printMenu();
        cout<<"Enter your choice : ";
        cin>>choice;

        if (choice==1)
        {
            int value;
            cout<<"Enter the value you want to push : ";
            cin>>value;
            s1.push(value);
            s1.current_state();
        }
        else if (choice==2)
        {
            int temp;
            temp=s1.pop();
            cout<<"The value popped is : "<<temp<<endl;
            s1.current_state();
        }
        else if (choice==3)
        {

            cout<<"The value at the top  is : "<<s1.peek()<<endl;
        }
        else if (choice==4)
        {
            int status=s1.isEmpty();
            string Status;

            if (status==1)
            {
                Status="True";
            }
            else
            {
                Status="False";
            }

            cout<<"The stack is Empty :  "<<Status<<endl;
        }
        else if (choice == 0)
        {
            cout<<"Thank You for using the program :)\n";
            break;
        }
        else
        {
            cout<<"Please enter a valid choice ! \n";
        }
    }




}
