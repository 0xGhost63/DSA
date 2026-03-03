#include <iostream>
using namespace std;


struct Node
{
    int value;
    Node* next;

};

class Linked_List
{
    public:
    Node* head;
    Node* tail;

    Linked_List()
    {
        head=tail=NULL;
    }

    void push_back(int value)
    {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->next = NULL;
    
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
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
    }
};
int main()
{
    Linked_List l;
    l.push_back(5);
    l.push_back(6);
    l.push_back(7);
    l.push_back(8);

    l.print();
}