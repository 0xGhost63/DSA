#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node * next;

};

class Circular_LL
{
    public:
        Node*head;
        Node*tail;

        Circular_LL()
        {
            head=NULL;
        }

        void push_front(int value)
        {
            Node * newNode = new Node;
            newNode->data=value;

            //First
            if(head==NULL)
            {
                head=newNode;
                newNode->next=head;
                print();
            }
            //Already Present
            else
            {
                Node*temp=head;
                while(temp->next!=head)
                {
                    temp=temp->next;
                }
                newNode->next=head;
                head=newNode;
                temp->next=head;
                print();

            }
        }

        void push_rear(int value)
        {
            Node * newNode = new Node;
            newNode->data=value;

            //First
            if(head==NULL)
            {
                head=newNode;
                newNode->next=head;
                print();
            }
            //Already Present
            else
            {
                Node*temp=head;
                while(temp->next!=head)
                {
                    temp=temp->next;
                }
                temp->next=newNode;
                newNode->next=head;
                print();

            }
        }

        void pop_rear()
        {

            if (head==NULL)
            {
                cout<<"The list is already empty !\n";
            }
            else if (head->next==head)
            {
                Node *temp=head;
                delete temp;
                head=NULL;
                print();
                return;
            }
            else
            {
                Node *nodeToPop=head;
                Node * prevNode=head;
                while(nodeToPop->next!=head)
                {
                    prevNode=nodeToPop;
                    nodeToPop=nodeToPop->next;
                }
                prevNode->next=head;
                delete nodeToPop;
                print();
            }
        }

        void pop_front()
        {
            if (head==NULL)
            {
                cout<<"Link-List is already Empty !\n";
                return;
            }
            else if (head->next==head)
            {
                Node*temp=head;
                delete temp;
                head=NULL;
                print();
                return;
            }
            else
            {
                Node*tail=head;
                while(tail->next!=head)
                {
                    tail=tail->next;
                }
                Node*temp=head;
                head=temp->next;
                tail->next=head;
                delete temp;
                print();

            }

        }
    void print()
    {
        if(head==NULL)
            return;

        Node* temp=head;

        do
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        while(temp!=head);

        cout<<"HEADDDD\n";
    }
};
int main()
{
    Circular_LL list;

    //Test-Cases !!

    cout<<"\n===== PHASE 1 : Build list =====\n";
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    list.push_front(5);

    cout<<"\n===== PHASE 2 : Rear insertions =====\n";
    list.push_rear(6);
    list.push_rear(7);
    list.push_rear(8);

    cout<<"\n===== PHASE 3 : Mixed deletions =====\n";
    list.pop_front();
    list.pop_rear();
    list.pop_front();
    list.pop_rear();

    cout<<"\n===== PHASE 4 : Rebuild again =====\n";
    list.push_front(9);
    list.push_rear(10);
    list.push_front(11);
    list.push_rear(12);

    cout<<"\n===== PHASE 5 : Rapid deletions =====\n";
    list.pop_front();
    list.pop_front();
    list.pop_rear();
    list.pop_rear();

    cout<<"\n===== PHASE 6 : Single node stress =====\n";
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front(); // should become empty

    cout<<"\n===== PHASE 7 : Reuse after empty =====\n";
    list.push_rear(100);
    list.push_front(200);
    list.push_rear(300);
    list.push_front(400);

    cout<<"\n===== PHASE 8 : Final destruction =====\n";
    list.pop_rear();
    list.pop_front();
    list.pop_rear();
    list.pop_front();

    cout<<"\n===== PHASE 9 : Empty again =====\n";
    list.pop_front();
    list.pop_rear();

    return 0;
}