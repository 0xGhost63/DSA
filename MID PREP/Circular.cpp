#include<iostream>
#define SIZE 5
using namespace std;

class Cirular_Queue
{
    public:

    int rear;
    int front;
    int arr[SIZE]={0};

    Cirular_Queue()
    {
        rear=-1;
        front=-1;
    }

    void insertion(int value)
    {
        if (front==(rear+1)%SIZE)
        {
            cout<<"STACK OVERFLOW\n";
        }
        else if (rear==-1)
        {

            rear=(rear+1)%SIZE;
            front=(front+1)%SIZE;
            arr[rear]=value;
        }
        else
        {
            rear=(rear+1)%SIZE;
            arr[rear]=value;
        }

    }

    void deletion()
    {
        if(rear==-1)
        {
            cout<<"Queue is empty\n";
        }
        else if(rear==front)
        {
            arr[front]=0;
            rear=-1;
            front=-1;
        }
        else
        {
            arr[front]=0;
            front=(front+1)%SIZE;
        }

    }
    void currentState()
    {
        cout << "The current elements in the queue are:\n";
        cout << "-------------------------------------------\n";

        for (int i = 0; i < SIZE; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < SIZE; i++)
        {
            cout << (i == front ? "F " : (i == rear ? "R " : "  "));
        }
        cout << endl;

        cout << "-------------------------------------------\n";
    }
    
};


void menu()
{
    cout << "\n======QUEUE MENU======\n";
    cout << "1-Enqueue \n";
    cout << "2-Dequeue \n";
    cout << "0-Exit\n";
    cout << "Enter your choice : ";
}
int main()
{
    Cirular_Queue  q;
    int choice, value;

    do
    {
        menu();
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.insertion(value);
                q.currentState();
                break;

            case 2:
                q.deletion();
                q.currentState();
                break;


            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}