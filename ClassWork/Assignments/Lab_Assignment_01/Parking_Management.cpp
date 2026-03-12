#include <iostream>
#define SIZE 4 //Size can be easily changed from here in case of gates > 4
using namespace std;
class Circular_Queue
{
    public:
    int front;
    int rear;
    string arr[SIZE]={"NORTH","EAST","SOUTH","WEST"};//Here i have initialized the str array(queue) with the 4 directions

    //Constructor--->initialzing the front & rear according to the array Initialization !
    Circular_Queue()
    {
        front=0;
        rear=SIZE-1;
    }
    //Method for addition !
    void insertion(string data)
    {
        if(front==-1&&rear==-1) //Empty Condition
        {
            front=rear=0;
            arr[rear]=data;
        }
        else if (front==(rear+1)%SIZE) //Full COndition
        {
            cout<<"Queue Overflow !!\n";
            return;

        }
        else //Normal Condition
        {
            rear=(rear+1)%SIZE;
            arr[rear]=data;
        }
    }
    string deletion()
    {
        //I will be using the "EMPTY" string to indicate the empty elements of the queue 
     
        if(front==-1&&rear==-1) //Empty Condition
        {
            cout<<"The queue is already empty !\n";
            return "EMPTY";
        }
        else if(front==rear)//last element condition 
        {
            string temp=arr[front];
            arr[front]="EMPTY";
            front=rear=-1;
            return temp;
        }
        else //Normal Condition !
        {
            string temp=arr[front];
            arr[front]="EMPTY";
            front=(front+1)%SIZE;
            return temp;
        }

    }
};

int main()
{
    Circular_Queue q;

    cout<<"\n======================================== PARKING MANAGEMENT ========================================\n";
    int cycles,vehicles;
    cout<<"Enter the Number of Cycles : ";
    cin>>cycles;
    vehicles=cycles*SIZE;
    cout<<"Total vehicles that will be parked in "<<cycles<<" cycles will be : "<<vehicles<<"\n\n";

    int counter=0;

    while(counter<cycles)
    {
        cout<<"[CYCLE # "<<counter+1<<"]\n";
        for(int i =0;i<SIZE;i++)
        {
            string temp=q.deletion();
            cout<<"* Vehicle is entering from the "<<temp<<" Gate\n";
            q.insertion(temp);
        }
        counter ++;
        cout<<endl;
    }
    cout<<"All "<<vehicles<<" vehicles have been parked,successfully !\n";
    cout<<"\n========================================================================================================\n";
    cout<<"Exiting the program....\n";

    return 0;
}