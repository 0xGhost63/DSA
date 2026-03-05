// In this program I'm learing to push the values at the end 
// and the start of the Linked List
// Tail pointer is not using ! Rather I'm looping over to find the Null pointer 

#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;

};
class Linked_List
{
    public:
    Node*head;

    Linked_List()
    {
        head=NULL;
    }

    void push_front(int x)
    {
        Node*newNode = new Node;
        newNode->value=x;

        //Empty Linked-List Condition ie head==Null
        if (head==NULL)
        {
            head=newNode;
            newNode->next=NULL;
        }
        //Already elements present condition !head==Null
        else
        {
            newNode->next=head;
            head=newNode;
        }

        cout<<"Value : "<<x<<" added to Linked-List !\n";
        cout<<"Current State of the Linked-List : ";
        print();


    }

    void push_back(int x)
    {
        Node* newNode = new Node;
        newNode->value=x;

        //Empty Linked-List Condition ie head==Null
        if (head==NULL)
        {
            head=newNode;
            newNode->next=NULL;
        }
        //Already elements present condition !head==Null
        else
        {
            Node *temp=head;

            while(!temp->next==NULL)
            {
                temp=temp->next;
            }

            temp->next=newNode;
            newNode->next=NULL;
            cout<<"Value : "<<x<<" added to Linked-List !\n";
            cout<<"Current State of the Linked-List : ";
            print();   
        }

    }
    void print()

    {
        Node* temp=head;

        while(temp!=NULL)
        {
            cout<<temp->value<<"->";
            temp=temp->next;
        }
        cout<<endl;
    }

};
int main()
{
    Linked_List l;
    l.push_front(3);
    l.push_front(2);
    l.push_front(1);
    l.push_front(0);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    l.push_back(7);

    return 0;
}