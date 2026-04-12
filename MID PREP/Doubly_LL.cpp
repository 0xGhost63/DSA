#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class Doubly
{
public:

    Node* head;
    Node* tail;

    Doubly()
    {
        head = NULL;
        tail = NULL;
    }

    // ================= INSERTION =================

    void front_push(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void rear_push(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insert_randomly(int pos, int value)
    {
        if (pos == 0)
        {
            front_push(value);
            return;
        }

        Node* temp = head;
        int counter = 0;

        while (temp != NULL && counter < pos - 1)
        {
            temp = temp->next;
            counter++;
        }

        if (temp == NULL)
        {
            cout << "Invalid Position!\n";
            return;
        }

        if (temp->next == NULL)
        {
            rear_push(value);
            return;
        }

        Node* newNode = new Node(value);

        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;
    }

    // ================= DELETION =================

    void delete_front()
    {
        if (head == NULL)
        {
            cout << "List already empty!\n";
            return;
        }

        Node* temp = head;

        if (head->next == NULL)
        {
            head = tail = NULL;
        }
        else
        {
            head = head->next;
            head->prev = NULL;
        }

        delete temp;
    }

    void delete_rear()
    {
        if (tail == NULL)
        {
            cout << "List already empty!\n";
            return;
        }

        Node* temp = tail;

        if (tail->prev == NULL)
        {
            head = tail = NULL;
        }
        else
        {
            tail = tail->prev;
            tail->next = NULL;
        }

        delete temp;
    }

    void delete_randomly(int pos)
    {
        if (head == NULL)
        {
            cout << "List already empty!\n";
            return;
        }

        if (pos == 0)
        {
            delete_front();
            return;
        }

        Node* temp = head;
        int counter = 0;

        while (temp != NULL && counter < pos)
        {
            temp = temp->next;
            counter++;
        }

        if (temp == NULL)
        {
            cout << "Invalid Position!\n";
            return;
        }

        if (temp->next == NULL)
        {
            delete_rear();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
    }

    // ================= DISPLAY =================

    void print_DLL()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
};

// ================= MENU =================

void menu()
{
    cout << "\n========= DOUBLY LINKED LIST =========\n";
    cout << "1  -> Insert at Front\n";
    cout << "2  -> Insert at Rear\n";
    cout << "3  -> Insert at Position\n";
    cout << "4  -> Delete from Front\n";
    cout << "5  -> Delete from Rear\n";
    cout << "6  -> Delete at Position\n";
    cout << "7  -> Display List\n";
    cout << "0  -> Exit\n";
    cout << "======================================\n";
    cout << "Enter choice: ";
}

// ================= MAIN =================

int main()
{
    Doubly DLL;

    int choice, value, pos;

    do
    {
        menu();
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                DLL.front_push(value);
                DLL.print_DLL();
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                DLL.rear_push(value);
                DLL.print_DLL();
                break;

            case 3:
                cout << "Enter position: ";
                cin >> pos;
                cout << "Enter value: ";
                cin >> value;
                DLL.insert_randomly(pos, value);
                DLL.print_DLL();
                break;

            case 4:
                DLL.delete_front();
                DLL.print_DLL();
                break;

            case 5:
                DLL.delete_rear();
                DLL.print_DLL();
                break;

            case 6:
                cout << "Enter position: ";
                cin >> pos;
                DLL.delete_randomly(pos);
                DLL.print_DLL();
                break;

            case 7:
                cout << "\nCurrent List:\n";
                DLL.print_DLL();
                break;

            case 0:
                cout << "\nExiting...\n";
                break;

            default:
                cout << "\nInvalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}