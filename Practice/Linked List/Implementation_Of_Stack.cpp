#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node * next;

};

class LinkedList
{
    public :

        Node * head;
        Node * top;

        LinkedList()
        {
            head=top=NULL;
        }

        // int at_top()
        // {
        //     if (!head->next==NULL)
        //     {
        //         return top->data;
        //     }
        //     else
        //     {
        //         cout<<"The linked-list(stack) is empty !\n";
        //         return 0;
        //     }
        // }

        bool isEmpty()
        {
            return head==NULL;
        }
        void push (int value)
        {
            Node * newNode = new Node;
            newNode->data=value;
            if (isEmpty())
            {
                string before = print();
                head=newNode;
                top=newNode;
                newNode->next=NULL;
                string after=print();
                // cout<<"Before : "<<before<<endl;
                cout<<"After  : "<<after<<endl;
            }
            else
            {
                string before=print();
                top->next=newNode;
                newNode->next=NULL;
                top=newNode;
                string after=print();
                // cout<<"Before : "<<before<<endl;
                cout<<"After  : "<<after<<endl;
            }
        }

        void pop()
        {
            if (isEmpty())
            {
                cout<<"The linked-list(stack) is already empty !\n";
                return;
            }
            else if (head->next==top->next)
            {
                
                free(head);
                top=head=NULL;
                string after=print();

                cout<<"After : "<<after<<endl;
                
            }
            else
            {
                string before=print();
                
                Node*temp=head;
                Node * prevNode=temp;
                while (temp->next!=NULL)
                {
                    prevNode=temp;
                    temp=temp->next;
                }
                top=prevNode;
                prevNode->next=NULL;
                free(temp);
                string after=print();
                // cout<<"Before : "<<before<<endl;
                cout<<"After  : "<<after<<endl;
            }
        }
        
        string print()
        {
            string s="";

            Node*temp=head;
            while(temp!=NULL)
            {
                s+=to_string(temp->data);
                s+="->";
                temp=temp->next;
            }
            s+="NULL\n";

            return s;
        }

};
int main ()
{
    LinkedList list;

    list.push(0);
    list.push(1);
    list.push(2);
    list.push(3);
    list.push(4);
    // // int top=list.at_top;
    // // cout<<"Top : "<<top<<endl;
    list.pop();//4
    list.pop();//3
    list.pop();//2
    list.pop();//1
    list.pop();//0
    list.pop();//EMPTY !

    list.push(4);
    list.push(3);
    list.push(2);
    list.push(1);
    list.push(0);

}
