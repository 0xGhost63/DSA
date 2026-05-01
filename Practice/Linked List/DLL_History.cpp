//This program practically uses the Doubly Linked List !

//REQUIREMENTS !
    /*Add 3 actions
    Type(text) → add new state after current
    Undo() → move current back one node
    Redo() → move current forward one node*/

// P.S : I MANUALLY IMPLEMENTED THE WHOLE DLL BUT USED ONLY THE "pushRear method" only in the program!

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
        Node *current;

        DLL()
        {
            head=NULL;
            tail=NULL;
            current=NULL;
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
            else if (head->next==NULL)
            {
                Node * temp=head;
                delete temp;
                head=tail=NULL;
                print_DLL();
            }
            else
            {
                Node *temp=head;
                head=head->next;
                head->prev=NULL;
                delete temp;
                print_DLL();
            }
        }

        void deleteRear()
        {
            if(head==NULL)
            {
                cout<<"Linked-List is already empty,can't delete :(\n";
            }
            else if (tail->prev==NULL)
            {
                Node * temp=tail;
                delete temp;
                head=tail=NULL;
                print_DLL();
            }
            else
            {
                Node *temp=tail;
                tail=tail->prev;
                tail->next=NULL;
                delete temp;
                print_DLL();
            }
        }

        void deleteRandomly(int pos)
        {
            if (head==NULL)
            {
                // cout<<"Enter the 1st  if block\n";
                cout<<"Linked-List is already empty,can't delete :(\n";
                return;
            }
            else if(tail->prev==NULL || head->next==NULL) //Only One Node 
            {
                cout<<"Enter the 1st else if block\n";
                Node * temp=tail;
                delete temp;
                head=tail=NULL;
                print_DLL();
                return;
            }
            else if (pos==0)
            {
                // cout<<"Enter the 2nd else if block\n";
                deleteFront();
                return;
            }
            else
            {
                // cout<<"Enter the else block\n";
                cout<<"The position is : "<<pos<<endl;
                Node *temp=head;
                
                int counter=0;
                while(counter<pos)
                {
                    temp=temp->next;
                    counter++;
                    cout<<"Reached : "<<temp->value<<endl;
                    
                }
                if(temp==tail)
                {
                    deleteRear();
                    return;
                }
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                delete temp;
                print_DLL();
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

        void initCurrent()
        {
            if (current==NULL)
            current=head;
        }
        void printCurrent()
        {
            cout<<"\n=====================CURRENT POS==========================\n";
            Node *temp=head;
            int counter=1;
            while(temp!=current)
            {
                cout<<"Step #"<<counter<<" "<<temp->value<<endl;
                temp=temp->next;
                counter++;
                
            }
            cout<<"Step #"<<counter<<" "<<temp->value<<endl;
            cout<<"\n==========================================================\n";
            
        }

        void undo()
        {
            initCurrent();
            if (head==NULL||head->next==NULL )
            cout<<"No node to move back...add some content first !\n";
            else if (current==head)
            {
                cout<<"Already at the edge of the node,can't move further !\n";
                return;
            }
            else
            {
                current=current->prev;
            }
        }
        void redo()
        {
            initCurrent();
            if ( head==NULL||head->next==NULL )
            {
                cout<<"No node to move forward...add some content first !\n";
                return;
            }
            else if (current==tail)
            {
                cout<<"Already at the edge of the node,can't move further !\n";
            }
            else
            {
                
                current=current->next;
            }
        }
};
void Menu()
{
    cout<<"\n====================MENU=============================\n";
    cout<<"1- Type\n";
    cout<<"2- Undo(BACKWARD)\n";
    cout<<"3- Redo(FORWARD)\n";
    cout<<"4- Run Test\n";
    cout<<"0- EXIT\n";
    cout<<"\n=====================================================\n";
    cout<<"Enter your choice : ";
}
void runTest();
int main()
{
    DLL list;
    int choice=-1;
    while(choice!=0)
    {
        Menu();
        cin>>choice;
        if (choice==1)
        {
            string content;
            cin.ignore();
            cout<<"Enter the content : ";
            getline(cin,content);
            list.push_rear(content);
            list.current=list.tail;
            list.printCurrent();
        }
        else if (choice==2)
        {
            list.undo();
            list.printCurrent();
        }
        else if (choice==3)
        {
            list.redo();
            list.printCurrent();
        }
        else if(choice==4)
        {
            runTest();
        }
        else if (choice ==0)
        {
            cout<<"Thank You for using the program :)\n";
        }
        else 
        {
            cout<<"Enter a valid choice plz 1-3,or 0 to EXIT\n";
        }
    }


    return 0;

}

void runTest()
{
        //Test CASES
    DLL list;
    cout<<"\n========== TEST 1: Undo/Redo on empty list ==========\n";
    list.undo();   // should print "add some content first"
    list.redo();   // should print "add some content first"

    cout<<"\n========== TEST 2: Type some content ==========\n";
    list.push_rear("Hello");
    list.current=list.tail;
    list.printCurrent();   // Hello

    list.push_rear("World");
    list.current=list.tail;
    list.printCurrent();   // World

    list.push_rear("Foo");
    list.current=list.tail;
    list.printCurrent();   // Foo

    // List is now: Hello <=> World <=> Foo

    cout<<"\n========== TEST 3: Undo ==========\n";
    list.undo();
    list.printCurrent();   // should be at World

    list.undo();
    list.printCurrent();   // should be at Hello

    cout<<"\n========== TEST 4: Undo at head (boundary) ==========\n";
    list.undo();           // should print "Already at the beginning!"
    list.printCurrent();   // should still be at Hello

    cout<<"\n========== TEST 5: Redo ==========\n";
    list.redo();
    list.printCurrent();   // should be at World

    list.redo();
    list.printCurrent();   // should be at Foo

    cout<<"\n========== TEST 6: Redo at tail (boundary) ==========\n";
    list.redo();           // should print "Already at the latest state!"
    list.printCurrent();   // should still be at Foo

    cout<<"\n========== TEST 7: Undo then Type (overwrite future) ==========\n";
    list.undo();
    list.printCurrent();   // at World
    list.push_rear("Bar");
    list.current=list.tail;
    list.printCurrent();   // at Bar
    // List is now: Hello <=> World <=> Foo <=> Bar

    cout<<"\n========== TEST 8: Single node undo/redo ==========\n";
    DLL list2;
    list2.push_rear("Only");
    list2.current=list2.tail;
    list2.undo();          // "No node to move back"
    list2.redo();          // "No node to move forward"

    cout<<"\n========== ALL TESTS DONE ==========\n";
}

