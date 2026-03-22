#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node*left;
    Node*right;

    //Constructor !
    Node(int value)
    {
        this->value=value;
        left=right=NULL;
    }
};

Node* insert(Node* root,int val)
{
    if (root==NULL)
    {
        return new Node(val);
    }
    else if (val<root->value)
    {
        root->left=insert(root->left,val);
    }
    else if (val>root->value)
    {
        root->right=insert(root->right,val);
    }

    return root;
}

void inorder(Node*root)
{
    if (root==NULL)
    {
        // cout<<"The tree is empty !!\n";
        return;
    }
    inorder(root->left);
    cout<<root->value<<" ";
    inorder(root->right);
}

int main() 
{
    Node* root = NULL;
    int val;
    while (true) 
    {
        cout << "Enter the value : ";
        cin >> val;
        if (val==-1)
         break;
        root = insert(root, val);
        inorder(root);
        cout << "\n";
    }

    cout << "Thank You...\n";
}