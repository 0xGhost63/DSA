#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int CAPACITY = 5;

class Queue 
{
    int* arr;
    int front, rear, size;

public:
    Queue() 
    {
        arr   = new int[CAPACITY];
        front = 0;
        rear  = 0;
        size  = 0;
    }

    bool isEmpty() 
    {
        return size == 0;
    }

    bool isFull() 
    {
        return size == CAPACITY;
    }

    bool enqueue(int val) 
    {
        if (isFull()) 
        {
            return false;
        }
        arr[rear] = val;
        rear = (rear + 1) % CAPACITY;
        size++;
        return true;
    }

    bool dequeue(int &val) 
    {
        if (isEmpty()) 
        {
            return false;
        }
        val   = arr[front];
        front = (front + 1) % CAPACITY;
        size--;
        return true;
    }

    int peek() 
    {
        if (isEmpty()) 
        {
            return -1;
        }
        return arr[front];
    }

    int getSize() 
    {
        return size;
    }

    void printState() 
    {
        cout << "ARR: ";
        for (int i = 0; i < CAPACITY; i++) 
        {
            bool used = false;
            for (int j = 0; j < size; j++) 
            {
                if ((front + j) % CAPACITY == i) 
                {
                    used = true;
                    break;
                }
            }
            if (used) 
            {
                cout << arr[i];
            } 
            else 
            {
                cout << "-";
            }
            if (i < CAPACITY - 1) 
            {
                cout << " ";
            }
        }
        int actualRear = (rear - 1 + CAPACITY) % CAPACITY;
        cout << " | front=" << front << " rear=" << actualRear << " size=" << size << endl;
    }
};

void showMenu()
{
    cout << "\n=====CMDS======\n";
    cout << "ENQ\n";
    cout << "DEQ\n";
    cout << "PEEK\n";
    cout << "SIZE \n";
    cout << "STATE\n";
    cout << "EXIT\n";
    cout << "================\n";
    cout<<">>>";
}
int main() 
{
    Queue q;
    string cmd;

    while (cmd!="EXIT") 
    {
        showMenu();
        cin>>cmd;
        if (cmd=="ENQ") 
        {
            int x;
            cout<<">>>";
            cin >> x;
            if (q.enqueue(x)) 
            {
                cout << "ENQ OK" << endl;
            } 
            else 
            {
                cout << "ENQ FAIL" << endl;
            }
        } 
        else if (cmd=="DEQ") 
        {
            int val;
            if (q.dequeue(val)) 
            {
                cout << "DEQ " << val << endl;
            } 
            else 
            {
                cout << "DEQ FAIL" << endl;
            }
        } 
        else if (cmd=="PEEK") 
        {
            int p = q.peek();
            if (p == -1) 
            {
                cout << "PEEK FAIL" << endl;
            } 
            else 
            {
                cout << "PEEK " << p << endl;
            }
        } 
        else if (cmd=="SIZE") 
        {
            cout << "SIZE " << q.getSize() << endl;
        } 
        else if (cmd=="STATE") 
        {
            q.printState();
        } 
        else if (cmd=="EXIT") 
        {
            cout<<"Thank Your for using the program :)\n";
            break;
        }
    }
    return 0;
}