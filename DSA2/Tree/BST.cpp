#include <iostream>
#include <queue>
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

Node *levelOrderTraveral(Node *root)
{
    if (root == NULL)
    {
        cout << "Empty Tree" << endl;
        return NULL;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            cout << temp->data << " ";
            q.pop();
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    return root;
}

Node *insertInBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data < root->data)
    {
        if (!root->left)
        {
            root->left = new Node(data);
        }
        else
        {
            insertInBST(root->left, data);
        }
    }
    else
    {
        if (!root->right)
        {
            root->right = new Node(data);
        }
        else
        {
            insertInBST(root->right, data);
        }
    }
    return root;
}

// from a root!
Node *createBST(Node *root)
{
    int data;
    cout << "Enter data to be inserted in BST" << endl;
    cin >> data;
    if (data == -1)
        return NULL;
    // while (data != -1)
    // {
    //     root = insertInBST(root, data);
    //     cout << "Enter next value to be inserted(-1 to stop):" << endl;
    //     cin >> data;
    // }
    root = insertInBST(root, data);
    createBST(root);
    return root;
}

int main()
{
    Node *root = NULL;
    root= createBST(root);
    levelOrderTraveral(root);
    return 0;
}