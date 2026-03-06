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
            string before=print();
            
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
            string after=print();
            cout<<"Before : "<<before<<endl;
            cout<<"After  : "<<after<<endl;

        }


        void pop_from_front()
        {
            string before=print();
            if (head==NULL)
            {
                cout<<"Link-List is already empty !\n";
            }
            else
            {
                Node * temp =head;
                head=temp->next;
                cout<<"DELETED !\n";
                cout<<"Node with value : "<<temp->value <<" and memory pointer : "<<temp->next<<endl;
                free(temp);
                string after=print();
                cout<<"Before : "<<before<<endl;
                cout<<"After  : "<<after<<endl;
            }
        }

        void pop_from_rear()
        {
            string before=print();
            if(head==NULL)
            {
                cout<<"The Linked-List is already empty !\n";
            }
            else 
            {
                Node * temp = head;
                Node * prevNode = temp;

                while(temp->next!=NULL)
                {
                    prevNode=temp;
                    temp=temp->next;
                }
                prevNode->next=NULL;
                cout<<"DELETED !\n";
                cout<<"Node with value : "<<temp->value <<" and memory pointer : "<<temp->next<<endl;
                free (temp);
                string after=print();
                cout<<"Before : "<<before<<endl;
                cout<<"After  : "<<after<<endl;

            }

        }




        void push_to_rear(int value)
        {
            Node* newNode = new Node;
            newNode->value=value;
            string before=print();

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
            string after=print();
            cout<<"Before : "<<before<<endl;
            cout<<"After  : "<<after<<endl;

        }

        void push_to_randomly(int pos,int value)
        {

            Node* temp =head;
            if(head==NULL)
            {
                cout<<"Linked list was empty...so pushing to rear !\n";
                string before = print();
                push_to_rear(value);
                string after=print();
                cout<<"Before : "<<before<<endl;
                cout<<"After  : "<<after<<endl;
                return;

            }

            else
            {
                Node * newNode= new Node;

                //In center
                while (temp!=NULL)
                {
                    string before=print();
                    if (temp->value==pos)
                    {
                        newNode->value=value;
                        newNode->next=temp->next;
                        temp->next=newNode;
                        cout<<"Value added : "<<value<<" after : "<<pos<<endl;
                        string after=print();
                        cout<<"Before : "<<before<<endl;
                        cout<<"After  : "<<after<<endl;
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
                        string after=print();
                        cout<<"Before : "<<before<<endl;
                        cout<<"After  : "<<after<<endl;
                        return;

                    }
                    temp=temp->next;
                }
            }



        }
        void delete_randomly(int pos)
        {
            string before=print();
            if (head==NULL)
            {
                cout<<"The Linked-List is already Empty !\n";
            }
            else if (pos==0)
            {
                pop_from_front();
            }
            else
            {
                Node * temp =head;
                Node* prevNode=temp;

                for (int i =0;i<pos;i++)
                {
                    prevNode=temp;
                    temp=temp->next;
                }
                if(temp->next==NULL)
                {
                    pop_from_rear();
                }
                else
                {
                    prevNode->next=temp->next;
                    cout<<"DELETED !\n";
                    cout<<"Node with value : "<<temp->value <<" and memory pointer : "<<temp->next<<" at position : "<<pos<<endl;
                    free (temp);
                    string after=print();
                    cout<<"Before : "<<before<<endl;
                    cout<<"After  : "<<after<<endl;
                }

            }
        }



        string print()
        {
            string s="";

            Node*temp=head;
            while(temp!=NULL)
            {
                s+=to_string(temp->value);
                s+="->";
                temp=temp->next;
            }
            s+="NULL\n";

            return s;
        }

};

void Menu()
{
    cout<<"=======================CHOOSE AN OPTION=======================\n";
    cout<<"1-Push to Front\n";
    cout<<"2-Push to Rear\n";
    cout<<"3-Push At Random Position\n";
    cout<<"4-Pop from Front\n";
    cout<<"5-Pop from Rear\n";
    cout<<"6-Pop From  Random Position\n";
    cout<<"0-EXIT\n";
    cout<<"==============================================================\n";
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
        else if(choice==4)
        {
            list.pop_from_front();
        }
        else if(choice==5)
        {
            list.pop_from_rear();
        }
        else if(choice==6)
        {
            int pos;
            cout<<"Enter the position of the value you want to delete (0-index-based) : ";
            cin>>pos;
            list.delete_randomly(pos);
        }

        else if(choice==0)
        {
            cout<<"Thank You for Using the program !\n";
        }
        else
        {
            cout<<"Enter a valid choice !!! :)\n";
        }
    }

    return 0;
}