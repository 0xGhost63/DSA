
/*

    NAME: SANNAN AHMAD
    ROLL # SP25-BSE-118
*/
#include <iostream>
using namespace std;
struct Node
{
    int value;
    Node *next;
};
 
class LinkList
{
    public:
        Node * head;
 
        LinkList()
        {
            head=NULL;
        }
 
        void frontInsertion(int value)
        {
            Node* newNode = new Node;
            newNode->value=value;
 
            if (head==NULL)
            {
                head=newNode;
                newNode->next=NULL;
            }
            else
            {
                newNode->next=head;
                head=newNode;
            }
 
        }
 
        void rearInsertion(int value)
        {
            Node* newNode = new Node;
            newNode->value=value;
 
            if (head==NULL)
            {
                head=newNode;
                newNode->next=NULL;
            }
            else
            {
                Node*temp=head;
 
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
 
                temp->next=newNode;
                newNode->next=NULL;
            }
 
        }
 
        void print()
        {
            Node*temp=head;
            while(temp!=NULL)
            {
                cout<<temp->value<<"->";
                temp=temp->next;
            }
            cout<<"NULL\n";
 
        }
 
        void findValue(int value)
        {
            Node*a=head;
            bool flag = true;
 
            while (a!=NULL)
            {
                Node*b=a->next; 
                while (b!=NULL)
                {
                    int sum=a->value+b->value;
                    if (sum==value)
                    {
                        cout<<"FOUND A PAIR :  "<<a->value<<" + "<<b->value<<" "<<endl;
                        flag=false;
                    }
                    b=b->next;
                }
                a=a->next;
            }
 
            if (flag)
            {
                cout<<"Haven't found a value mathching with the : "<<value;
            }
 
        }
 
};
int main()
{
    LinkList list;
 
    int input=0;
    while (input != -1)
    {
        int choice;
        cout<<"Enter the value (-1 to EXIT): ";
        cin>>input;

        if (input == -1) break;

        cout<<"At front or rear ?\n";
        cout<<"1-Front \n";
        cout<<"2-REAR\n";
        cout<<" >>> ";
        cin>>choice;
        if (choice==1)
        {
            list.frontInsertion(input);
        }
        else if(choice==2)
        {
            list.rearInsertion(input);
        }
        else
        {
            // default to rear
            list.rearInsertion(input);
        }
 
    }

    list.print(); 

    int toFind;
 
    cout<<"Enter the sum value to find : ";
    cin>>toFind;
    list.findValue(toFind);
 
    cout<<"\nFIN...THANK YOU FOR USING THE PROGRAM :)\n"; 
 
   
 
    return 0;
}