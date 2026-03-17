//This program practically uses the Doubly Linked List !
#include <iostream>
using namespace std;
struct Node
{
    string value;
    Node * next;
    Node * prev;
};
class DLL
{
    public:
        Node *head;
        Node *tail;

        DLL()
        {
            head=NULL;
            tail=NULL;
        }

        void push_front(string value)
        {
            Node * newNode = new Node;
            newNode->value=value;
            if (head==NULL)
            {   
                head=newNode;
                tail=newNode;
                newNode->prev=NULL;
                newNode->next=NULL;
                print_DLL();
            }
            else
            {
                newNode->next=head;
                newNode->prev=NULL;
                newNode->next->prev=newNode;
                head=newNode;
                print_DLL();
            }
        }

        void push_rear(string value)
        {

            Node * newNode = new Node;
            newNode->value=value;
            if (head==NULL)
            {   
                head=tail=newNode;
                newNode->prev=NULL;
                newNode->next=NULL;
                // cout<<"IF_CASE\n";
                print_DLL();
            }
            else
            {
                newNode->prev=tail;
                newNode->next=NULL;
                newNode->prev->next=newNode;
                tail=newNode;
                // cout<<"ELSE_CASE\n";
                print_DLL();
            }
        }

        void pushRandomly(int pos,string value)
        {
            Node * newNode = new Node;
            newNode->value=value;
            if (head==NULL)
            {
                cout<<"Linked-List was already empty,so pushing to front...\n";
                push_front(value);
                delete newNode;
            }
            else if(pos==0)
            {
                push_front(value);
                delete newNode;
            }
            else
            {
                Node * currentNode=head;
                int counter=0;
                pos--;
                while(counter!=pos)
                {
                    currentNode=currentNode->next;
                    counter++;
                }
                if(currentNode==tail)
                {
                    push_rear(value);
                }
                else
                {
                    newNode->prev=currentNode;
                    newNode->next=currentNode->next;
                    newNode->prev->next=newNode;
                    newNode->next->prev=newNode;
                    print_DLL();
                }

            }
        }

        void deleteFront()
        {
            if(head==NULL)
            {
                cout<<"Linked-List is already empty,can't delete :(\n";
            }
        }

        void print_DLL()
        {
            string s="";
            Node*temp=head;
            while(temp!=NULL)
            {
                s+=(temp->value);
                s+="<=>";
                temp=temp->next;
            }
            s+="NULL\n";
            cout<<s<<endl;
        }
};
int main()
{

    DLL list;
    // list.push_front("3");  
    // list.push_front("2");
    // list.push_front("1");
    // list.push_front("0");
    // list.push_rear("0");
    // list.push_rear("1");
    // list.push_rear("2");
    // list.push_rear("3");

    // for (int i =0;i<5;i++)
    // {
    //     int pos=i;
    //     string value=to_string(i);
    //     list.pushRandomly(pos,value);
    // }
    // list.pushRandomly(5,"63");


    return 0;

}