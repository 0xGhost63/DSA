#include <iostream>
using namespace std;


//I'M IMPLMENTING THE BASIC LINK-LIST HERE TO USE FOR THE STACK-->Stack Implementation through Linked-List(only necessary methods are implemented) !

struct Node
{
    int data;
    Node*next;

    //Constructor For The Struct !
    Node (int val)
    {
        this->data=val;
        next=NULL;
    }
};
class LinkedList
{
    public:

    Node*head; //I'm Basically utilizing the head as the TOP of the stack i.e both insertion & deletion from the head end

    LinkedList()
    {
        head=NULL;
    }

    void push(int val)
    {
        Node* newNode= new Node(val);
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

    void pop()
    {
        if (head==NULL)
        {
            cout<<"NOTHING TO DELETE !!\n";
        }
        else
        {
            Node *temp=head;
            head=temp->next;
            delete (temp);
        }
    }

    bool isEmpty()
    {
        return (head==NULL);
    }

    int peek()
    {
        if (isEmpty())
        {
            cout<<"The stack is empty !\n";
            return 0;
        }
        else
        return head->data;
    }


    void print ()
    {
        Node*temp=head;
        bool first_element=true;
        cout<<"The elements in the stack are : \n";
        while(temp!=NULL)
        {
            if (first_element)
            {
                cout<<temp->data<<" <---- TOP "<<endl;
                first_element=0;
                
            }
            else
            cout<<temp->data<<endl;
            temp=temp->next;
        }
        cout<<endl;

    }
};

//NOW IMPLEMENTING THE STACK HERE :-

class Stack
{
    public :

    int attempt=0;
    int score = 0;
    int stack_size=0;
    const int  maxAttempts = 10;
    const int winSize = 5;
    bool game_over=false;
    bool win=false;

    LinkedList list;

    void push(int val)
    {
        int top=list.peek(); //retrieving the top value of the stack for the comparison


        if (list.isEmpty())
        {
            list.push(val);
            score+=2;
            attempt++;
            stack_size++;
        }
        else if (val<=top)
        {
            list.push(val);
            attempt++;
            stack_size++;
            score+=2;
            
        }
        else
        {
            cout<<"Oh No ! Game Over :(\n";
            game_over=true;
        }
    }

    void pop()
    {
        if (!list.isEmpty())
        {
            list.pop();
            score--;
            attempt++;
            stack_size--;
        }
    }
};

void menu()
{
    cout<<"=====================STACK THE PLATES=====================\n";
    cout<<"1-Push the Plate\n2-Pop the Plate\n3-Peek the top\n4-Display the overall Stack\n0-Exit\n";
}

int main()
{
    Stack stack;
    int choice, val;
    
        // No. of attempts Reached          // Stack Collapsed   // Player Won
    while(stack.attempt<stack.maxAttempts && !stack.game_over && stack.stack_size!=5)
    {
        menu();
        cout<<"Enter your choice: ";
        cin>>choice;
        
        switch(choice)
        {
            case 1:
                cout<<"Enter weight of the plate to be pushed : ";
                cin>>val;
                stack.push(val);
                if(!stack.game_over)
                    stack.list.print();
                break;
            case 2:
                stack.pop();
                stack.list.print();
                break;
            case 3:
                if (!stack.list.isEmpty())
                    cout<<"Weight of the top plate : "<<stack.list.peek()<<endl;
                else
                    cout<<"The stack of plates is empty yet :)\n";
                break;
            case 4:

                break;
            case 0:
                cout<<"Thank you for playing ! :) ...\n";
                return 0;
            default:
                cout<<"Please Enter a valid choice !\n";
                break;
        }
    }
    
    return 0;
}

//IMPLEMENT THE DISPLAY FUNCTION !
