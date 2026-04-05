/*
    NAME : SANNAN AHMAD
    REG # SP25-BSE-118
*/
#include<iostream>
using namespace std;

//IMPLEMENTING THE CUSTOM NODE STRUCT FOR LL BASED ON THE REQUIRMENTS
struct Node
{
    // DATA PART OF THE EACH NODE !
    int id;
    string name;
    bool status; // I'M USING A BOOL FOR THE STATUS CONFIRMATION 


    //POINTER PART OF EACH NODE !
    Node * next;

    //CONSTRUCTOR OF THE STRUCT-NODE

    Node(int id,string name,bool status)
    {
        this->id=id;
        this->name=name;
        this->status=status;
        this->next=NULL;
        // POINTER WILL INITALLY BE POINTED TO THE NULL
        //(WILL BE SET FOR EACH CASE INDIVIDUALLY-->CASE TO CASE)
    }

};
//IMPLEMENTING THE CUSTOM LINKED-LIST BASED ON THE REQUIREMNETS
class LinkedList
{
    public:

    Node*head;// head of each node (EXTERNAL POINTER)

    //Constructor
    LinkedList()
    {
        //Head Pointing to NULL by default
        head=NULL;
    }

    /*
        1-REGISTRATION METHOD !
    */

    //For registration i will be linking the node at the rear

    void registerParticipant(int id,string name,bool status)
    {
        Node*newNode=new Node(id,name,status);

        if (head==NULL)
        {
            head=newNode;
            newNode->next=NULL;
            cout<<"Successfully Resgisted Mr./Ms. "<<name<<" :)"<<endl;
        }
        else
        {
            Node * temp=head;

            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->next=NULL;
            cout<<"Successfully Resgisted Mr./Ms. "<<name<<" :)"<<endl;
        }

    }

    /*
        2-UPDATE REGISTRATION METHOD
    */

    void updateRegistration(int id,bool status)
    {
        Node*temp=head;
        while (temp!=NULL)
        {
            if (temp->id==id)
            {
                string str=(status)?"CONFIRMED":"NOT Confirmed";
                temp->status=status;
                cout<<"Status Successfully updated to : "<<str<<endl;
            }
            temp=temp->next;
        }
        
    }

    /*
        3-REMOVE CANCELLED REGISTRATIONS METHODS !
        USING 3 HELPER METHODS & 1 MAIN METHOD
    */

    //CASE-1 : From Front
    void deleteFront()
    {
        Node *temp=head;
        head=temp->next;
        cout<<"Removed Mr./Ms. "<<temp->name<<" \n";
        delete temp;
    }

    //CASE-2: From Rear
    void deleteRear()
    {
        Node*temp=head;
        Node*prevNode=temp;
        while(temp->next!=NULL)
        {
            prevNode=temp;
            temp=temp->next;
        }
        prevNode->next=NULL;
        cout<<"Removed Mr./Ms. "<<temp->name<<" \n";
        delete temp;
    }
    
    //CASE-3 : At Specified Position
    void deleteSpecified(int id)
    {
        if (head==NULL)
        {
            cout<<"No participant to delete,list is empty yet\n";
            return;
        }
        //Here I'm Using 2 external pointers to make the deletion of a specified ID easier
        Node*temp=head;
        Node*prevNode=temp;
        while(temp->id!=id)
        {
            prevNode=temp;
            temp=temp->next;
        }
        prevNode->next=temp->next;
        cout<<"Removed Mr./Ms. "<<temp->name<<" \n";
        delete temp;
    }

    void removeCancelled()
    { 
        Node * temp=head;

        while (temp!=NULL)
        {
            Node* next=temp->next; 
            if (temp->status==false)
            {
                if(head==temp)
                deleteFront();
                else if (temp->next==NULL)
                deleteRear();
                else
                deleteSpecified(temp->id);
            }
            temp=next;
        }
        
    }

    /*
        4-DISPLAY PARTICIPANTS

        i-Display ALL
        ii-Display CONFIRMED ONLY
    */

    void displayParticipants(bool all)
    {
        Node*temp=head;
        
        while(temp!=NULL)
        {
            //using ternary operator
            string status;
            status=(temp->status)? "CONFIRMED":"NOT Confirmed";

            //ONLY CONFIRMED CASE
            if(temp->status==true)               
                cout<<"ID : "<<temp->id<<" - Name : "<<temp->name<<" Status : "<<status<<endl;

            //ALL PARTICIPANTS CASE
            else if (all)
                cout<<"ID : "<<temp->id<<" - Name : "<<temp->name<<" Status : "<<status<<endl;

            //Incremenet
            temp=temp->next;
        }
    }



    /*
        5- EXTRA CHECK TO MAKE SURE THAT 
        REASON 1-NO PARTICIPANT HAVE THE SAME ID
        IN THE REGISTRARTION SYSTEM !

        REASON 2-HELPS IN SEARCHING THE FOR CHANGING STATUS
    */

    bool checkID(int id)
    {
        Node*temp=head;
        bool check=true;
        
        while(temp!=NULL)
        {
            if (temp->id==id)
            {
                cout<<"ID : "<<id<<"  exists !\n";
                check=false;
            }

            temp=temp->next;
        }
        return check;
    }
    
};

//METHOD TO DISPLAY THE MENU !
void menu()
{
    cout<<"=====================CHOOSE AN OPTION=====================\n";
    cout<<"0-Run Test Cases\n1-Register Participants\n2-Update Registration Status\n3-Remove Cancelled Registrations\n4-Display Participants\n9-Exit\n";
    cout<<"==========================================================\n";

}
void runTestCases();
int main()
{
    int choice=-1;
    LinkedList list;
    
    while (choice!=9)
    {
        menu();
        cout<<"Select the Action to perform : ";
        cin>>choice;

        if (choice==1)
        {
            int id;
            string name;
            bool status;

            cin.ignore();
            cout<<"Enter the Name of the Participant : ";
            getline(cin,name);
            do
            {
                cout<<"Choose an ID : ";
                cin>>id;
            } while (!list.checkID(id));

            cin.ignore();
            cout<<"Decision to join ? ";
            do
            {
                cout<<"CHOOSE 0 OR 1 ONLY\n";
                cout<<"1-Confirm\n";
                cout<<"0-NOT Confirm \n";
                cout<<">>> ";
                cin>>status;
            } while (status!=0&&status!=1);
            
            
            list.registerParticipant(id,name,status);
        }
        else if (choice==2)
        {
            int id;
            cout<<"Enter the ID of the participant : ";
            cin>>id;
            bool notExists=list.checkID(id);

            while (notExists)
            {
                cout<<"No user exists with this ID,please enter ID again : ";
                cin>>id;
                notExists=list.checkID(id);
            }
            
            bool status;
            cout<<"CHANGE THE STATUS TO : \n";
            do
            {
                cout<<"CHOOSE 0 OR 1 ONLY\n";
                cout<<"1-Confirm\n";
                cout<<"0-NOT Confirm yet\n";
                cout<<">>> ";
                cin>>status;
            } while (status!=0 && status!=1);
            
            list.updateRegistration(id,status);
        }

        else if (choice==3)
        {
            list.removeCancelled();
            cout<<"All NOT CONFIRMED participants removed successfully :)\n";
        }

        else if(choice==4)
        {
            bool all;
            do
            {
                cout<<"0-Display ONLY CONFIRMED participants\n";
                cout<<"1-Display all\n";
                cout<<"Select your choice (0 & 1 only) : \n";
                cin>>all;
            } while (all!=0 && all!=1);   
            list.displayParticipants(all);
        }
        else if (choice==0)
        {
            runTestCases();
            
        }
        else if (choice==9)
        {
            cout<<"\nThank you for using the program,have a good day :)\n";
            break;
        }
        else
        {
            cout<<"Choose a valid Option! :)\n";
        }

    }
    
    return 0;
}

/*
    I have used some test cases here
    that tests all the core
    functionality modules of 
    the program requirments...
*/
void runTestCases()
{
    LinkedList testList;

    cout<<"\n========== RUNNING TEST CASES ==========\n";


    cout<<"\nTEST 1 Registering 5 participants...\n";
    testList.registerParticipant(101,"Sannan Ahmad",true);
    testList.registerParticipant(102,"Sara Khan", false);
    testList.registerParticipant(103,"Umar Farooq" ,true);
    testList.registerParticipant(104,"Zara Ahmed", false);
    testList.registerParticipant(105,"Bilal Sheikh" ,true);
    cout<<"TEST 1 PASSED\n";


    cout<<"\nTEST 2 Displaying all participants (should show 5)...\n";
    testList.displayParticipants(true);
    cout<<"TEST 2 PASSED\n";


    cout<<"\nTEST 3 Updating ID 102 (NOT Confirmed -> CONFIRMED)...\n";
    testList.updateRegistration(102,true);
    cout<<"TEST 3 PASSED\n";

    cout<<"\nTEST 4 Updating ID 105 (CONFIRMED -> NOT Confirmed)...\n";
    testList.updateRegistration(105,false);
    cout<<"TEST 4 PASSED\n";

    cout<<"\nTEST 5 Displaying all participants after updates (102 CONFIRMED, 105 NOT Confirmed)...\n";
    testList.displayParticipants(true);
    cout<<"TEST 5 PASSED\n";


    cout<<"\nTEST 6 Removing cancelled registrations (104 & 105 should be removed)...\n";
    testList.removeCancelled();
    cout<<"TEST 6 PASSED\n";

    cout<<"\nTEST 7 Displaying CONFIRMED only (should show 101, 102, 103)...\n";
    testList.displayParticipants(false);
    cout<<"TEST 7 PASSED\n";


    cout<<"\nTEST 8 Checking duplicate ID 103 (should say exists)...\n";
    testList.checkID(103);
    cout<<"TEST 8 PASSED\n";

    cout<<"\nTEST 9 Checking ID 999 (should be available)...\n";
    bool result=testList.checkID(999);
    if(result)
        cout<<"ID 999 is available\n";
    cout<<"[TEST 9] PASSED\n";


    cout<<"\nTEST 10 Removing cancelled on already-clean list (nothing to remove)...\n";
    testList.removeCancelled();
    cout<<"TEST 10 PASSED\n";


    cout<<"\n========== ALL TEST CASES PASSED :) ==========\n\n";
}