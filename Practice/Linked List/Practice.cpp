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
    Node* headNode;
    Node* tailNode;

    Linked_List()
    {
        headNode=tailNode=NULL;
    }

    void push_back(int value)
    {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->next = NULL;

        if (headNode == NULL)
        {
            headNode = tailNode = newNode;
        }
        else
        {
            tailNode->next = newNode;
            tailNode = newNode;
        }
    }
    void print()

    {
        Node* temp=headNode;

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