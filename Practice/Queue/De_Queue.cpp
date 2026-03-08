#include <iostream>
using namespace std;
#define SIZE 5
class Dequeue
{
    public:
    int front;
    int rear;
    int arr [SIZE]={0};

    Dequeue()
    {
        front=rear=-1;
    }

    void rear_push(int value)
    {
        if (front==-1 && rear ==-1)
        {
            front++;
            rear++;
            arr[rear]=value;
            currentState();
        }
        else if (front==(rear+1)%SIZE) 
        {
            cout<<"Queue Overflow !\n";
            currentState();
        }
        else 
        {
            rear=(rear+1)%SIZE;
            arr[rear]=value;
            currentState();
        }
    }

    void front_pop()
    {
        if (front==-1 && rear ==-1)
        {
            cout<<"The queue is already empty !\n";
            currentState();
        }
        else if (front==rear) 
        {
            arr[front]=0;
            rear=front=-1;
            currentState();
        }
        else 
        {
            arr[front]=0;
            front=(front+1)%SIZE;
            currentState();
        }

    }

    void push_front(int value)
    {
        if (front==-1 && rear ==-1)
        {
            front++;
            rear++;
            arr[front]=value;
            currentState();
        }
        else if (front==(rear+1)%SIZE) 
        {
            cout<<"Queue Overflow !\n";
            currentState();
        }
        else 
        {
            front=(front-1+SIZE)%SIZE;
            arr[front]=value;
            currentState();
        }
    }
    void rear_pop()
    {
        if (front==-1 && rear ==-1)
        {
            cout<<"The queue is already empty !\n";
            currentState();
        }
        else if (front==rear) 
        {
            arr[rear]=0;
            rear=front=-1;
            currentState();
        }
        else 
        {
            arr[rear]=0;
            rear=(rear-1+SIZE)%SIZE;
            currentState();
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
int main()
{
    Dequeue queue;

    cout << "\n===== TEST 1: Basic rear_push =====\n";
    queue.rear_push(10);
    queue.rear_push(20);
    queue.rear_push(30);

    cout << "\n===== TEST 2: Basic push_front =====\n";
    queue.push_front(5);
    queue.push_front(1);

    cout << "\n===== TEST 3: Overflow Test =====\n";
    queue.rear_push(99);  // should overflow

    cout << "\n===== TEST 4: front_pop =====\n";
    queue.front_pop();
    queue.front_pop();

    cout << "\n===== TEST 5: rear_pop =====\n";
    queue.rear_pop();
    queue.rear_pop();

    cout << "\n===== TEST 6: Refill after pop =====\n";
    queue.rear_push(100);
    queue.rear_push(200);
    queue.push_front(50);

    cout << "\n===== TEST 7: Empty the queue =====\n";
    queue.front_pop();
    queue.front_pop();
    queue.front_pop();
    queue.rear_pop();  // last element

    cout << "\n===== TEST 8: Underflow Test =====\n";
    queue.front_pop();  
    queue.rear_pop();   

    cout << "\n===== TEST 9: Refill after full empty =====\n";
    queue.push_front(7);
    queue.rear_push(8);

    return 0;
}