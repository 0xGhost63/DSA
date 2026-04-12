#include <iostream>
using namespace std;
class L_Queue{
    public:
    int front=-1;
    int rear=-1;
    int size=10;
    int arr[10]={0};

    void insertion(int value){
        if( rear==size-1)
        {
            cout<<"Queue is overflown";
             
        }
        else if(rear==-1 && front==-1)
        {
            rear=0;
            front=0;
            arr[rear]=value;

            cout<<"CAse 1\n";
        }
        else
        {
            rear++;
            arr[rear]=value;
            cout<<"CAse 2\n";
        }
    }
    void deletion()
        {
            if(front==-1)
            {
                cout<<"Queue is under flown\n";

            }
            else if(front==rear){
                arr[front]=0;
                front=rear=-1;
            }
            else
            {
                arr[front]=0;
                front++;

            }

            
        }

        void currentState()
        {
            for (int i : arr)
            {
               cout<<i<<" ";
            }
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
    L_Queue q;
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