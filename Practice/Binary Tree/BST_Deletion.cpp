#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node*left;
    Node*right;

    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};


Node* insert(Node*root,int val)
{
    if (root==NULL)
        return new Node(val);
    else if (val<root->data)
        root->left=insert(root->left,val);
    else if (val>root->data)
        root->right=insert(root->right,val);

    return root;
}

bool searchBST(Node*root,int key)
{
    if (root==NULL)
        return false;
    else if (key<root->data)
        return searchBST(root->left,key);
    else if (key>root->data)
        return searchBST(root->right,key);
    else
        return true;
}
void inorderBST(Node*root)
{
    if (root==NULL)
        return;
    else
    {
        inorderBST(root->left);
        cout<<root->data<<" ";
        inorderBST(root->right);
    }
}

Node *inorderSuccessor(Node*root)
{
    Node*temp=root;
    while(temp!=NULL && temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}

Node* deleteBST(Node*root,int val)
{
    if (root==NULL)
        return NULL;
    
    if (val<root->data)
        root->left=deleteBST(root->left,val);
    else if (val>root->data)
        root->right=deleteBST(root->right,val);
    else
    {
        if (root->left==NULL)
        {
            Node*temp=root->right;
            free (root);
            return temp;
        }
        else if (root->right==NULL)
        {
            Node*temp=root->left;
            free (root);
            return temp;
        }

        Node*succ=inorderSuccessor(root->right);
        root->data=succ->data;
        root->right=deleteBST(root->right,succ->data);
    }
    return root;
}
int main()
{
    //AI-GENERATED MENU FOR TESTING !
    int choice;
    Node* root = NULL;

    while (true) {
        cout << "\n=== BST Menu ===\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Delete\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int val;
            cout << "Enter value to insert: ";
            cin >> val;
            root = insert(root, val);
        } else if (choice == 2) {
            int key;
            cout << "Enter value to search: ";
            cin >> key;
            if (searchBST(root, key))
                cout << "Found!\n";
            else
                cout << "Not found!\n";
        } else if (choice == 3) {
            cout << "Inorder: ";
            inorderBST(root);
            cout << "\n";
        } else if (choice == 4) {
            int val;
            cout << "Enter value to delete: ";
            cin >> val;
            root = deleteBST(root, val);
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}