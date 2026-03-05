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

        void push_to_front(int value)
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
            cout<<"Value added to the front : "<<value<<endl;
            cout<<"The current state of the Linked-List is : ";
            print();
        }



        void push_to_rear(int value)
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
            cout<<"Value added to the rear : "<<value<<endl;
            cout<<"The current state of the Linked-List is : ";
            print();

        }

        void push_to_randomly(int pos,int value)
        {

            Node* temp =head;
            if(head==NULL)
            {
                cout<<"Linked list was empty...so pushing to rear !\n";
                push_to_rear(value);
                return;

            }

            else
            {
                Node * newNode= new Node;

                //In center
                while (temp!=NULL)
                {
                    if (temp->value==pos)
                    {
                        newNode->value=value;
                        newNode->next=temp->next;
                        temp->next=newNode;
                        cout<<"Value added : "<<value<<" after : "<<pos<<endl;
                        cout<<"The current state of the Linked-List is : ";
                        print();
                        return;

                    }
                    //at the end
                    else if (temp->next==NULL && temp->value==pos)
                    {
                        // newNode->value=value;
                        // newNode->next=NULL;
                        // temp->next=newNode;
                        push_to_rear(value);
                        cout<<"Value added : "<<value<<" after : "<<pos<<endl;
                        cout<<"The current state of the Linked-List is : ";
                        print();
                        return;

                    }
                    temp=temp->next;
                }
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

};

void Menu()
{
    cout<<"=======================CHOOSE AN OPTION=======================\n";
    cout<<"1-Push to Front\n";
    cout<<"2-Push to Rear\n";
    cout<<"3-Push At Random Position\n";
    cout<<"0-EXIT\n";
    cout<<"Enter the Option : ";

}
int main ()
{
    LinkList list;

    int choice=1;


    while (choice!=0)
    {
        Menu();
        cin>>choice;
        if (choice==1)
        {
            int value;
            cout<<"Enter the value : ";
            cin>>value;
            list.push_to_front(value);

        }
        else if (choice==2)
        {
            int value;
            cout<<"Enter the value : ";
            cin>>value;
            list.push_to_rear(value);
        }
        else if (choice==3)
        {
            int value=0;
            int pos=0;
            cout<<"Enter the value : ";
            cin>>value;
            cout<<"Add after which value ? : ";
            cin>>pos;

            list.push_to_randomly(pos,value);

        }
        else
        {
            cout<<"Enter a valid choice !!! :)\n";
        }
    }

    return 0;
}