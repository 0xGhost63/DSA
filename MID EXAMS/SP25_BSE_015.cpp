#include <iostream>
using namespace std;

class Queue
{
    int *arr ;
    int front , rear , size , capacity ;

public:

    Queue(int cap)
    {
        capacity = cap ;
        arr = new int[capacity] ;

        front = 0 ;
        rear  = -1 ;
        size = 0 ;
    }

    ~Queue()
    {
        delete[] arr ;
    }

    bool enqueue(int x)
    {
        if (size == capacity)
            return false ;

        rear = (rear + 1) % capacity ;
        arr[rear] = x ;
        size++ ;

        return true ;
    }

    bool dequeue(int &x)
    {
        if (size == 0)
            return false ;

        x = arr[front] ;
        front = (front + 1) % capacity ;
        size-- ;

        return true ;
    }

    int peek()
    {
        if (size == 0)
            return -1 ;

        return arr[front] ;
    }

    int getSize()
    {
        return size ;
    }

    void state()
    {
        cout << "\n[ Queue State ]\n";
        cout << "ARR : " ;

        for (int i = 0 ; i < capacity ; i++)
        {
            bool used = false ;

            for (int j = 0 ; j < size ; j++)
            {
                int idx = (front + j) % capacity ;

                if (idx == i)
                {
                    cout << arr[i] << " " ;
                    used = true ;
                    break ;
                }
            }

            if (!used)
                cout << "_ " ;
        }

        cout << "\nfront = " << front 
             << " , rear = " << rear 
             << " , size = " << size << endl ;
    }
};


void showMenu()
{
    cout<<"\n========== QUEUE CONTROL PANEL ==========\n";
    cout<<" ENQ-> insert\n";
    cout<<" DEQ-> remove\n";
    cout<<" PEEK-> front element\n";
    cout<<" SIZE-> current size\n";
    cout<<" STATE-> display queue\n";
    cout<<" EXIT-> quit\n";
    cout<<"=========================================\n";
}


int main()
{
    Queue q(5) ;

    char cmd[10] ;

    while (true)
    {
        showMenu();

        cout << ">> ";
        cin >> cmd ;

        // ENQ
        if (cmd[0]=='E' && cmd[1]=='N' && cmd[2]=='Q')
        {
            int x ;
            cout << "Enter value : ";
            cin >> x ;

            if (q.enqueue(x))
                cout << "ENQ OK\n" ;
            else
                cout << "ENQ FAIL\n" ;
        }

        else if (cmd[0]=='D')
        {
            int x ;

            if (q.dequeue(x))
                cout << "DEQ OK : " << x << endl ;
            else
                cout << "DEQ FAIL\n" ;
        }

        else if (cmd[0]=='P')
        {
            int val = q.peek() ;

            if (val == -1)
                cout << "PEEK FAIL\n" ;
            else
                cout << "TOP : " << val << endl ;
        }

        else if (cmd[0]=='S' && cmd[1]=='I')
        {
            cout << "SIZE" << q.getSize() << endl ;
        }

        else if (cmd[0]=='S' && cmd[1]=='T')
        {
            q.state() ;
        }

        else if (cmd[0]=='E' && cmd[1]=='X')
        {
            cout << "THANK YOU :)\n";
            break ;
        }

        else
        {
            cout << "Invalid command\n";
        }
    }

    return 0 ;
}