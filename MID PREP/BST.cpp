#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node*left;
    Node*right;
    Node(int data)
    {
        this->left=NULL;
        this->right=NULL;
        this->data=data;
    }
};

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
Node * insert(Node*root,int value)
{
    if (root==NULL)
        return new Node(value);
    else if (value<root->data)
        root->left=insert(root->left,value);
    else if (value>=root->data)
        root->right=insert(root->right,value);

    return root;
}

Node * inorderSucc(Node*root)
{
    Node*temp=root;
    while(temp!=NULL&&temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}
Node* deletion(Node*root,int value)
{
    if (root==NULL)
        return NULL;
    else if (value<root->data)
        root->left=deletion(root->left,value);
    else if (value>root->data)
        root->right=deletion(root->right,value);
    else
    {
        if (root->left==NULL)
        {
            Node*temp=root->right;
            delete (root);
            return temp;
        }
        else if (root->right==NULL)
        {
            Node*temp=root->left;
            delete (root);
            return temp;
        }

        Node* succ=inorderSucc(root->right);
        root->data=succ->data;
        root->right=deletion(root->right,succ->data);
    }
    return root;
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
int main()
{
    
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
            root = deletion(root, val);
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}