#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createTree(Node *root)
{
    cout << "Enter data:" << endl;
    int x;
    cin >> x;
    if (x == -1)
    {
        return NULL;
    }
    root = new Node(x);
    cout << "Enter data to insert in left of " << x << endl;
    root->left = createTree(root->left);
    cout << "Enter data to insert in right of " << x << endl;
    root->right = createTree(root->right);
    return root;
}

Node* preOrder(Node* root){
    if(root==NULL){
        return NULL;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);

    return root;
}

Node* inOrder(Node* root){
    if(root==NULL){
        return NULL;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);

    return root;
}
Node* postOrder(Node* root){
    if(root == NULL){
        return NULL;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";

    return root;
}
int main(){
    Node* root = NULL;
    root =  createTree(root);
    cout<<"\nPre Order Traversal"<<endl;
    preOrder(root);
    cout<<"\nIn Order Traversal"<<endl;
    inOrder(root);
    cout<<"\nPost Order Traversal"<<endl;
    postOrder(root);
    return 0;
}