#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;
    Node*prev;
};

class Doubly_LL
{
    public:
        Node * head;
        Doubly_LL()
        {
            head=NULL;
        }

        void push_front(int value)
        {
            Node * newNode=new Node;
            newNode->value=value;

            if(head==NULL)
            {
                head=newNode;
                newNode->next=NULL;
                newNode->prev=NULL;
                print_DLL();
            }
            else
            {
                newNode->next=head;
                head->prev=newNode;
                head=newNode;
                newNode->prev=NULL;
                print_DLL();
            }
        }

        void push_rear(int value)
        {
            Node * newNode=new Node;
            newNode->value=value;

            if (head==NULL)
            {
                head=newNode;
                newNode->next=NULL;
                newNode->prev=NULL;
                print_DLL();
            }
            else
            {
                Node*temp=head;
                // cout<<"Started from : "<<temp->value<<endl;
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                    // cout<<"Reached : "<<temp->value<<endl; //DEBUGGING CODE !
                }
                // cout<<"Loop break : "<<temp->value<<endl;
                temp->next=newNode;
                newNode->prev=temp;
                newNode->next=NULL;
                print_DLL();
            }
        }

        void push_random(int value,int pos)
        {
            Node* newNode = new Node;
            newNode->value=value;

            Node*temp=head;

            int counter=0;
            if (head==NULL)
            {
                cout<<"Linked-List was already empty,so pushing to rear :)\n";
                push_front(value); // :P
            }
            else if (pos==0)
            {
                push_front(value);
                print_DLL();
                return;
            }
            else
            {
                pos--;
                while(counter!=pos && temp!=NULL)
                {
                    temp=temp->next;
                    counter++;
                }
                if(temp->next==NULL)
                {
                    push_rear(value);
                    return;
                }
                newNode->prev=temp;
                newNode->next=temp->next;
                temp->next->prev=newNode;
                temp->next=newNode;
                print_DLL();
            }

        }
        void delete_front()
        {
            if (head==NULL)
            {
                cout<<"Linked-List is already empty,can't delete :(\n";
                return;
            }
            else
            {
                Node*temp=head;
                head=temp->next;
                if (head!=NULL)
                head->prev=NULL;
                //Good-Boy Habits
                temp->next=NULL;
                temp->prev=NULL;
                delete temp;;
                print_DLL();
            }
        }
        void delete_rear()
        {
            if (head==NULL)
            {
                cout<<"Linked-List is already empty,can't delete :(\n";
                return;
            }
            else
            {
                Node*temp=head;
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                if(temp->prev!=NULL)
                temp->prev->next=NULL;
                else
                head=NULL;
                //GOOD BOY HABITZZZ
                temp->next=NULL;
                temp->prev=NULL;
                

                delete temp;;
                print_DLL();
            }
        }

        void delete_randomly(int pos)
        {
            if(head==NULL)
            {
                cout<<"Linked-List is already empty,can't delete :(\n";
                return;
            }
            else if (pos==0)
            {
                delete_front();
            }
            else 
            {
                Node*temp=head;
                int counter=0;
                // pos--;
                while(counter!=pos&& temp!=NULL)
                {
                    temp=temp->next;
                    counter++;
                }
                if (temp->next==NULL) //Last Element
                {
                    delete_rear();
                    return;
                }
                else // if(head->prev!=NULL) //If NOT last element in the LL
                {
                    temp->prev->next=temp->next;
                    temp->next->prev=temp->prev;
                    delete temp;
                    print_DLL();
                    return;
                }
                // else // IF LAST ELEMENT IN THE LL
                // {
                //     //YK :P
                //     temp->next=NULL;
                //     temp->prev=NULL;
                //     head=NULL;
                //     delete temp;
                //     print_DLL();
                // }



            }
            


        }
        
        void print_DLL()
        {
                string s="";

                Node*temp=head;
                while(temp!=NULL)
                {
                    s+=to_string(temp->value);
                    s+="<=>";
                    temp=temp->next;
                }
                s+="NULL\n";

                cout<<s<<endl;
        }
};

int main()
{
    Doubly_LL DLL;
    int choice, value, pos;

    do {
        cout << "\n===== DOUBLY LINKED LIST MENU =====\n";
        cout << "1-Push Front\n";
        cout << "2-Push Rear\n";
        cout << "3-Push at Position\n";
        cout << "4-Delete Front\n";
        cout << "5-Delete Rear\n";
        cout << "6-Delete at Position\n";
        cout << "7-Run Test Case\n";
        cout << "0-Exit\n";
        cout << "===================================\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                DLL.push_front(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                DLL.push_rear(value);
                break;

            case 3:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> pos;
                DLL.push_random(value, pos);
                break;

            case 4:
                DLL.delete_front();
                break;

            case 5:
                DLL.delete_rear();
                break;

            case 6:
                cout << "Enter position: ";
                cin >> pos;
                DLL.delete_randomly(pos);
                break;

            case 7:

                // Empty the existing DLL first
                while (DLL.head != NULL)
                    DLL.delete_front();

                cout << "\n--- Building: 1<=>2<=>3<=>4<=>5 ---\n";
                DLL.push_rear(1);
                DLL.push_rear(2);
                DLL.push_rear(3);
                DLL.push_rear(4);
                DLL.push_rear(5);

                cout << "\n--- Delete front ---\n";
                DLL.delete_front();

                cout << "\n--- Delete rear ---\n";
                DLL.delete_rear();

                cout << "\n--- Delete middle (pos 1) ---\n";
                DLL.delete_randomly(1);

                cout << "\n--- Delete on empty ---\n";
                DLL.delete_front();
                DLL.delete_rear();
                DLL.delete_front();
                DLL.delete_front();
                DLL.delete_randomly(0);
                break;

            case 0:
                cout << "Good-Byeeeeeee!\n";
                break;

            default:
                cout << "Invalid choice, try again.\n";
        }

    } while (choice != 0);

    return 0;
}
// int main()
// {

//     Doubly_LL DLL;
//     DLL.push_front(5);
//     DLL.push_front(4);
//     DLL.push_front(3);
//     DLL.push_front(2);
//     DLL.push_front(1);
//     DLL.push_front(0);
//     DLL.push_rear(5);
//     DLL.push_random(63,1);
//     DLL.push_random(63,7);
//     cout<<"\n---DELETING RANDOMLY  FROM HERE ON---\n\n";
//     DLL.delete_randomly(0);
//     DLL.delete_randomly(4);
//     DLL.delete_randomly(2);
//     DLL.delete_randomly(1);
//     cout<<"\n---DELETING FROM REAR FROM HERE ON---\n";
//     DLL.delete_rear();
//     DLL.delete_rear();
//     DLL.delete_rear();
//     DLL.delete_rear();
//     DLL.delete_rear();
//     DLL.delete_rear();
//     DLL.delete_rear();



//     return 0;
// }