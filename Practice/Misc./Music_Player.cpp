#include <iostream>
#include <vector>
#define MAX 10
using namespace std;


struct Song 
{
    int id;
    char title[100];
    char artist[100];
    int play_count;
};

struct Node
{
    struct Song data;
    Node*next;   

    Node(Song data)
    {
        this->data=data;
        this->next=NULL;
    }
};

class Stack
{
    int top;
    Song arr[MAX];
    Stack()
    {
        this->top=top;
    }

    void push(Song data)
    {
        if (top==MAX-1)
        {
            cout<<"ERROR: Stack-OverFlow\n";
        }
        else
        {
            top++;
            arr[top]=data;
        }
    }
    void pop()
    {
        if (top==-1)
        {
            cout<<"ERROR:Stack under-flow!\n";
        }
        else
        {
            top--;
            //Hehe...ignoring the index instead of deleting 
        }
    }
};
class Linked_List
{
    public:
    Node*head;

    Linked_List()
    {
        this->head=NULL;
    }

    void push_to_front(Song data)
    {
        Node*newNode=new Node(data);

        if (head==NULL)
        {
            newNode->next=NULL;
            head=newNode;
        }
        else
        {
            newNode->next=head;
            head=newNode;
        }
    }

    void push_to_rear(Song data)
    {
        Node*newNode=new Node(data);

        if (head==NULL)
        {
            newNode->next=NULL;
            head=newNode;
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

    void push_randomly(Song data,int pos)
    {
        Node*newNode=new Node(data);

        if(pos==0)
        {
            push_to_front(data);
            delete newNode;
        }
        else
        {
            pos--;
            int counter=0;
            Node*temp=head;
            while(counter!=pos)
            {
                if(temp->next==NULL)
                {
                    cout<<"ERROR:The position to delete : "<<pos<<" doesn't exist !\n";
                    return;
                }
                temp=temp->next;
                counter++;
            }
            if (temp->next==NULL)
            {
                push_to_rear(data);
                delete newNode;
            }
            else
            {
                newNode->next=temp->next;
                temp->next=newNode;
            }
        }
    }


    void pop_front()
    {
        if(head==NULL)
        {
            cout<<"The linked-list is already empty !\n";
        }
        else if (head->next==NULL)
        {
            Node*temp=head;
            delete temp;
            head=NULL;
        }
        else
        {
            Node*temp=head;
            head=temp->next;
            cout<<"Deleted the node : "<<temp->data.title<<endl;
            delete (temp);
        }
    }


    void pop_rear()
    {
        if (head==NULL)
        {
            cout<<"The linked-list is already empty\n";
        }
        else if (head->next==NULL)
        {
            Node*temp=head;
            delete temp;
            head=NULL;
        }
        else
        {
            Node*temp=head;
            Node*prevNode=temp;
            while(temp->next!=NULL)
            {
                prevNode=temp;
                temp=temp->next;
            }
            prevNode->next=NULL;
            delete (temp);
            
        }   
    }

    void pop_randomly(int pos)
    {
        if (head==NULL)
        {
            cout<<"The linked-list is already empty !\n";
        }
        else if (pos==0)
        {
            pop_front();
            return;
        }
        else
        {
            Node*temp=head;
            Node*prevNode=temp;
            int counter=0;

            while(counter!=pos)
            {
                prevNode=temp;
                if(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                else
                {
                    cout<<"The selected position/song does'nt exist in the record!\n";
                    return;
                }
                counter++;
            }
            if(temp->next==NULL)
            {
                pop_rear();
            }
            else
            {
                prevNode->next=temp->next;
                delete(temp);
            }
            
        }
    }    

};

class Linear_Queue
{
    public:

    int front;
    int rear;
    Song arr [MAX];

    Linear_Queue()
    {
        this->front=-1;
        this->rear=-1;
    }
    void enqueue(Song data)
    {
        if (front==-1&&rear==-1)
        {
            front++;
            rear++;
            arr[rear]=data;
        }
        else if(rear==(MAX-1))
        {
            cout<<"The queue is already filled,can't add the new song :(\n";
        }
        else
        {
            rear++;
            arr[rear]=data;
        }
    }
    //Managing the array the smart way :P,by ignoring the instance of the struct that we want to delete & by not actually deleting it
    void dequeue()
    {
        if (front==-1&&rear==-1)
        {
            cout<<"The queue is already empty!\n";
        }
        else if (front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front++;
        }
    }
};

class Circular_Queue
{
    public :

    int front;
    int rear;
    Song arr[MAX];

    Circular_Queue()
    {
        this->front=-1;
        this->rear=-1;
    }

    void enqueue(Song data)
    {
        if (front==-1 && rear==-1)
        {
            front++;
            rear++;
            arr[rear]=data;
        }
        else if (front==(rear+1)%MAX)
        {
            cout<<"The Circular Queue is already full !\n";
        }
        else
        {
            rear=(rear+1)%MAX;
            arr[rear]=data;
        }
    }

    //Using the same ignoring method as in the linear queue
    void dequeue()
    {
        if (front==-1&&rear==-1)
        {
            cout<<"The circular Queue is already empty!\n";
        }
        else if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=(front+1)%MAX;
        }
    }

};

struct BST_Node
{
    Song data;
    BST_Node*left;
    BST_Node*right;

    BST_Node(Song data)
    {
        this->data=data;
        this->right=NULL;
        this->left=NULL;
    }
};

BST_Node* insertBST(BST_Node*root,Song data)
{
    if (root==NULL)
    {
        return new BST_Node(data);
    }
    else if (data.id<root->data.id)
    {
        root->left=insertBST(root->left,data);
    }
    else if (data.id>root->data.id)
    {
        root->right=insertBST(root->right,data);
    }

    return root;
}

bool BST_Search(BST_Node*root,int id)
{
    if (root==NULL)
    return false;
    else if (id<root->data.id)
       return  BST_Search(root->left,id);
    else if (id>root->data.id)
        return BST_Search(root->right,id);
    else if (id==root->data.id)
        return true;

}

void BST_Inorder(BST_Node*root)
{
    if (root==NULL)
    return;
    else
    {
        BST_Inorder(root->left);
        cout<<root->data.id<<"- "<<root->data.title<<" by "<<root->data.artist<<" and is played "<<root->data.play_count<<" times\n";
        BST_Inorder(root->right);
    }
}


void menu()
{
    cout<<"============================================\n";
    cout<<"MAIN MENU\n";
    cout<<"============================================\n";
    cout<<" [1] Playlist Manager     → (Linked Lists)\n";
    cout<<" [2] Play Queue           → (Linear & Circular Queue)\n";
    cout<<" [3] Song History         → (Stack)\n";
    cout<<" [4] Search / Stats       → (BST)\n";
    cout<<" [0] Exit\n";
    cout<<"============================================\n";
}
int main()
{
    //WHATS LEFT ??

    /*
    Step 1 → Stack class
    Step 2 → BST deletion (3 cases)
    Step 3 → Doubly Linked List class
    Step 4 → Make both linked lists circular
    Step 5 → Hardcode 10 songs, wire everything into main()
    Step 6 → Build the 4 menus
    */

    cout<<"Hello World\n";
    return 0;
}