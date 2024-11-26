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

// Depth wise creation
// first left left then right and uska bi left left then right
Node *createTree(Node *root)
{
    cout << "Enter data:" << endl;
    int x;
    cin >> x;

    if (x == -1)
        return NULL;

    root = new Node(x);
    cout << root->data;
    cout << "Enter left child of " << x << endl;
    root->left = createTree(root->left);
    cout << "Enter right child " << x << endl;
    root->right = createTree(root->right);
    return root;
}

// in prev one toh jb bi vo call hoga we need new Node always thats why can make outside!

// from non empty tree
// we can't create new Node by inserting data outside, bcz when it has left then toh we don need to create new Node na, so why would it make node agin again when it is called!
Node *create(Node *root)
{
    cout << "current node " << root->data << endl;
    if (root->left)
    {
        create(root->left);
    }
    else
    {
        cout << "Enter left child of " << root->data << endl;
        int data;
        cin >> data;
        if (data != -1)
        {
            root->left = new Node(data);
            create(root->left);
        }
    }

    if (root->right)
    {
        create(root->right);
    }
    else
    {
        cout << "Enter right child of " << root->data << endl;
        int data;
        cin >> data;
        if (data != -1)
        {
            root->right = new Node(data);
            create(root->right);
        }
        //else just move to right na😉
    }
    return root;
}

// Bredth wise creation
// first root in a queue, then create nd push its right and left and popping first and pushing their left, right leading to breadth search!
Node *createTreeFromLevelOrder(Node *root)
{
    queue<Node *> q;
    if (root == NULL)
    {
        cout << "Enter data for root" << endl;
        int rootData;
        cin >> rootData;
        if (rootData == -1)
            return NULL;
        // root->data = rootData;
        root = new Node(rootData);
    }

    cout << "current node " << root->data << endl;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (!temp->left)
        {
            cout << "\nEnter left child of " << temp->data << endl;
            int leftData;
            cin >> leftData;
            if (leftData != -1)
            {
                temp->left = new Node(leftData);
                q.push(temp->left);
            }
        }
        else
        {
            cout << temp->left->data << " ";
            q.push(temp->left);
        }

        if (!temp->right)
        {
            cout << "\nEnter right child of " << temp->data << endl;
            int rightData;
            cin >> rightData;
            if (rightData != -1)
            {
                temp->right = new Node(rightData);
                q.push(temp->right);
            }
        }
        else
        {
            cout << temp->right->data << " ";
            q.push(temp->right);
        }
    }
    return root;
}

// Node* createATree(Node* root, int arr[]){
//     if(root==NULL){
//         root= new Node(arr[0]);
//         createATree(root, arr);
//     }

// }

Node *traverseTree(Node *root)
{
    if (root == NULL)
        return NULL;

    traverseTree(root->left);
    cout << root->data << " ";
    traverseTree(root->right);
}

int main()
{
    // Node *root = NULL;
    Node *root = new Node(8);
    // root->left = new Node(4);
    // root->right = new Node(10);
    // root = createTree(root);
    // root = createTreeFromLevelOrder(root);
    root = create(root);
    traverseTree(root);
    return 0;
}