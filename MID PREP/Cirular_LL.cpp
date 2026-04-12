#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
class Circular_Queue
{
    public:

    Node *head;
    Circular_Queue()
    {
        head=NULL;
    }
    void frontInsertion(int value)
    {
        Node*newNode=new Node(value);
        if (head==NULL)
        {
            head=newNode;
            newNode->next=head;
        }
        else
        {
            Node*temp=head;
            while(temp->next!=head)
                temp=temp->next;
            temp->next=newNode;
            newNode->next=head;
            head=newNode;
        }
    }

    void insertionRear(int value)
    {
        Node*newNode=new Node(value);
        if (head==NULL)
        {
            head=newNode;
            newNode->next=head;
        }
        else
        {
            Node*temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->next=head;
            
        }
    }

    void deleteionFront()
    {
        if (head==NULL)
        {
            cout<<"LL is already,Empty\n";
        }
        else if(head->next==head)
        {
            Node*temp=head;
            head=NULL;
            delete temp;
            return;
        }
        else
        {

            Node*first=head;
            Node*temp=head;
            while(temp->next!=head)
                temp=temp->next;
            
            head=head->next;
            temp->next=head;
            delete first;
        }
    }
    void deleteionRear()
    {
        if (head==NULL)
        {
            cout<<"LL is already,Empty\n";
        }
        else if(head->next==head)
        {
            Node*temp=head;
            head=NULL;
            delete temp;
        }
        else
        {
            Node*temp=head;
            Node*prevNode=temp;
            while(temp->next!=head)
            {
                prevNode=temp;
                temp=temp->next;
            }
            prevNode->next=head;
            delete temp;

        }
    }

    void pushRandomly(int value,int pos)
    {
        if (pos==0)
        {
            frontInsertion(value);
            return;
        }
        else 
        {
            Node*newNode=new Node(value);
            Node *temp=head;
            int counter=0;
            while(counter!=pos)
            {
                if(temp==head && counter!=0)
                {
                    cout<<"Invalid Position\n";
                    return;
                }
                else
                {
                    temp=temp->next;
                    counter++;
                }
            }
            if(temp->next==head)
            {
                insertionRear(value);
                return;
            }
            
            newNode->next=temp->next;
            temp->next=newNode;
            
                
        }

    }

    void deleteRandomly(int pos)
    {
        if (pos==0)
        {
            deleteionFront();
            return;
        }
        else 
        {
            Node *temp=head;
            Node*prevNode=temp;
            int counter=0;

            while(counter!=pos)
            {
                if(temp==NULL&& counter!=0)
                {
                    cout<<"Invalid Position\n";
                    return;
                }
                else
                {
                    prevNode=temp;
                    temp=temp->next;
                    counter++;
                }
            }
            if(temp->next==head)
            {
                deleteionRear();
                return;
            }            
            prevNode->next=temp->next;
            delete temp;

            
                
        }

    }

    void print()
    {
        Node*temp=head;
        int counter=0;
        do
        {
            cout<<temp->data<<"<=>";
            temp=temp->next;
            counter++;
        }while(temp!=head);

        cout<<"BACK TO "<<head->data<<endl;
    }
    
};

int main()
{
    Circular_Queue cq;
    int choice, value;

    while(true)
    {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at Rear\n";
        cout << "3. Delete from Front\n";
        cout << "4. Delete from Rear\n";
        cout << "5. Print Queue\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter value to insert at front: ";
                cin >> value;
                cq.frontInsertion(value);
                cq.print();
                break;
            case 2:
                cout << "Enter value to insert at rear: ";
                cin >> value;
                cq.insertionRear(value);
                cq.print();
                break;
            case 3:
                cq.deleteionFront();
                cq.print();
                break;
            case 4:
                cq.deleteionRear();
                cq.print();
                break;
            case 5:
                cq.print();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}