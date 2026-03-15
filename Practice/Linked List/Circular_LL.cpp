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


        void push_to_randomly(int pos,int value)
        {

            Node* temp =head;
            if(head==NULL)
            {
                cout<<"Linked list was empty...so pushing to rear !\n";
                string before = "";
                push_rear(value);
                print();
                return;

            }

            else
            {
                Node * newNode= new Node;

                //In center
                do
                {
                    if (temp->data==pos)
                    {
                        newNode->data=value;
                        newNode->next=temp->next;
                        temp->next=newNode;
                        cout<<"Value added : "<<value<<" after : "<<pos<<endl;
                        print();
                        return;

                    }
                    temp=temp->next;
                }
                while(temp!=head);

            }

        }

        void delete_randomly(int pos)
        {
            if (head==NULL)
            {
                cout<<"The Linked-List is already Empty !\n";
            }
            else if (pos==0)
            {
                pop_front();
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
                if(temp->next==head)
                {
                    pop_rear();
                }
                else
                {
                    prevNode->next=temp->next;
                    cout<<"DELETED !\n";
                    cout<<"Node with value : "<<temp->data <<" and memory pointer : "<<temp->next<<" at position : "<<pos<<endl;
                    delete temp;
                    print();
                }

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

void menu()
{

    cout << "\n=================== Circular Linked List Menu ===================\n";
    cout << "1. Push Front\n";
    cout << "2. Push Rear\n";
    cout << "3. Pop Front\n";
    cout << "4. Pop Rear\n";
    cout << "5. Print List\n";
    cout << "6. Push Randomly\n";
    cout << "7. Delete Randomly\n";
    cout << "8. Exit\n";
    cout<<"======================================================================\n";
    cout << "Enter your choice : ";
    
}

int main()
{
    Circular_LL list;

    int choice=0;
    while(choice!=8)
    {
        menu();
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                int value;
                cout << "Enter the value to push : ";
                cin >> value;
                list.push_front(value);
                break;
            }
            case 2:
            {
                int value;
                cout << "Enter the value to push : ";
                cin >> value;
                list.push_rear(value);
                break;
            }
            case 3:
                list.pop_front();
                break;
            case 4:
                list.pop_rear();
                break;
            case 5:
                list.print();
                break;

            case 6:
            {
                int pos,value;
                cout<<"Enter the node value after which you want to insert : ";
                cin>>pos;
                cout<<"Enter value to insert : ";
                cin>>value;
                list.push_to_randomly(pos,value);
                break;
            }

            case 7:
            {
                int pos;
                cout<<"Enter index to delete (0-index baseed) : ";
                cin>>pos;
                list.delete_randomly(pos);
                break;
            }

            case 8:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    }

}