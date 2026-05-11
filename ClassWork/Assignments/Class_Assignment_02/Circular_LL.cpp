#include <iostream>
using namespace std;

struct Node
{
    string agentName;
    Node*next;


    Node(string agentName)
    {
        this->agentName=agentName;
        next=NULL;
    }
};

class Circular_Linked_List
{
    public: 
    Node*head=NULL;
    Node*current=NULL;

    void addAgent(string name)
    {
        Node * newNode= new Node(name);

        if(head==NULL)
        {
            current=newNode;
            head=newNode;
            newNode->next=head;
        }
        else
        {
            Node*temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->next=head;
        }
    }

    void printAgents()
    {
        if (head==NULL)
        {
            cout<<"NO agents present in the Call Center :( \n";
        }
        else
        {
            cout<<"\n============AVAILABE AGENTS ARE================\n";
            Node*temp=head;

            do
            {
                cout<<temp->agentName<<"->";
                temp=temp->next;
            } while(temp!=head);
            cout<<" -> Back to agent : "<<head->agentName;
            cout<<"\n===============================================\n";
        }
    }

    void assignAgent(int callNumb)
    {
        if (!current)
        {
            cout<<"NO agents present in the Call Center :( \n";
        }
        else
        {
            cout<<"Call : "<<callNumb<<" has been assigned to Mr. "<<current->agentName<<endl;
            current=current->next;
        }
    }

};
int main()
{
    Circular_Linked_List callCenter ; 
    int agents,calls;

    cout<<"Enter the number of agents \n>> ";
    cin>>agents;
    cin.ignore();
    for (int i =0 ;i<agents;i++)
    {
        string temp;
        cout<<"Enter the name of the agent # "<<i+1<<" : ";
        getline(cin,temp);
        callCenter.addAgent(temp);
    }

    callCenter.printAgents();
    
    cout<<"Enter the number of calls\n>> ";
    cin>>calls;

    for (int j=1;j<=calls;j++)
    {
        callCenter.assignAgent(j);
    }
}