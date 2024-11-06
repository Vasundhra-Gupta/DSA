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

// Node *createTree(Node *root, int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         Node *newNode = new Node(arr[i]);
//         if (root == NULL)
//         {
//             root = newNode;
//             return root;
//         }
//         if (root->left == NULL)
//         {
//             root->left = newNode;
//             return root;
//         }
//         else
//         {
//             createTree(root->left, arr[i]);
//         }
//         if (root->right == NULL)
//         {
//             root->right = newNode;
//             return root;
//         }
//         else
//         {
//             createTree(root->left, arr[i])
//         }
//         createTree(newNode, arr[i]);
//     }
//     return root;
// }

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

Node *createTreeFromLevelOrder(Node *root)
{
    queue<Node *> q;
    cout << "Enter data for root" << endl;
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    // root->data = rootData;
    root = new Node(rootData);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter data to insert in left of " << temp->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter data to insert in right of " << temp->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
    return root;
}
int main()
{
    Node *root = NULL;
    // createTree(root);
    root = createTreeFromLevelOrder(root);
    return 0;
}