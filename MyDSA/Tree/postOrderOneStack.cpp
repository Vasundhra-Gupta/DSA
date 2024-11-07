#include <iostream>
using namespace std;
#include <stack>
#include <vector>

// USING 1 STACK

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
    stack <Node*> st;
    Node *temp = root;

    while (true)
    {
        if (temp)
        {
            st.push(temp);
            temp = temp->left;
        }
        else
        {
            if (st.empty() == true) break;
            temp = st.top()->right;
            if(temp==NULL){
                temp= st.top();
                cout<<st.top()->data;
                st.pop();
                //This is wt responsible to sending temp back to wt we want(It means you go bck till u have right)
                while(!st.empty && temp== st.top()->right){
                    temp = st.top();
                    cout<<st.top()->data;
                    st.pop();
                }
            }
        }
    }
}

int main()
{
    Node *root = NULL;
    root = createTree(root);
    postOrderIterative(root);
    return 0;
}