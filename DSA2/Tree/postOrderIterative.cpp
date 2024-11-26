#include <iostream>
using namespace std;
#include <stack>
#include <vector>

// USING 2 STACK

class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int val)
    {
        this->data = val;
        this->right = NULL;
        this->left = NULL;
    }
};

Node *createTree(Node *root)
{
    cout << "Enter data:\n";
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    root = new Node(data);
    cout << "Enter to insert in left of " << root->data << endl;
    root->left = createTree(root->left);
    cout << "Enter to insert in right of " << root->data << endl;
    root->right = createTree(root->right);

    return root;
}

Node *postOrderIterative(Node *root)
{
    stack<Node *> st1, st2;

    if (root == NULL)
    {
        return NULL;
    }

    st1.push(root);

    while(!st1.empty()){
        Node* temp = st1.top();
        cout<<temp->data<<" "<<endl;
        st2.push(temp);
        st1.pop();

        if(temp->left){
            st1.push(temp->left);
        }

        if(temp->right){
            st1.push(temp->right);
        }
    }
    int size = st2.size();
    for(int i=0; i<size; i++){
        cout<<st2.top()->data<<" ";
        st2.pop();
    }

    return root;
}

int main()
{
    Node *root = NULL;
    root = createTree(root);
    postOrderIterative(root);
    return 0;
}