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

// Level order Traversal
// push root in queue
//  and till empty list
// find front ele and then pop
// then if right child exist then push
//  if left child exist then push

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        { // old level traversed
            cout << endl;
            if (!q.empty())
            { // separator for next level
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << "\t";
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
}

int main()
{
    Node *root = NULL;
    root = createTree(root);
    levelOrderTraversal(root);
    return 0;
}