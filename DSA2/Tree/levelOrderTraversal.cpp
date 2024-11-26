#include <iostream>
#include <queue>
#include <vector>
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

// now to print as a tree , 1st appraoch is like we can use separator using NULL when a level finishes
// and the other could be u store each level element in a data structure(like list of arrays)

//take first nd print nd  push its left right, then again, then again!

vector<vector<int>> levelOrderTraveral(Node *root)
{
    vector<vector<int>> list;
    if (root == NULL)
    {
        return list;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            level.push_back(temp->data);
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
        list.push_back(level);
    }
    return list;
}

// reverseLevelOrderTraversal
// vector<vector<int>> reverseLevelOrderTraversal(Node *root)
// {
//     vector<vector<int>> list;
//     if (root == NULL)
//     {
//         return list;
//     }
//     queue<Node *> q;
//     q.push(root);

//     while (!q.empty())
//     {
//         int size = q.size();
//         vector<int> level;
//         for (int i = 0; i < size; i++)
//         {
//             Node *temp = q.front();
//             q.pop();
//             level.push_back(temp->data);

//             if (temp->left)
//             {
//                 q.push(temp->left);
//             }
//             if (temp->right)
//             {
//                 q.push(temp->right);
//             }
//         }
//         list.push_back(level);
//         //traversal from back;;;
//     }
//     return list;
// }

void printList(vector<vector<int>> list)
{
    cout << "List: \n";
    for (int i = 0; i < list.size(); i++)
    {
        vector<int> level = list[i];
        for (int j = 0; j < level.size(); j++)
        {
            cout << level.at(j) << "\t";
        }
        cout << endl;
    }
}

int main()
{
    Node *root = NULL;
    vector<vector<int>> list1, list2;
    root = createTree(root);
    list1 = levelOrderTraveral(root);
    printList(list1);
    // list2 = reverseLevelOrderTraversal(root);
    // printList(list2);
    return 0;
}