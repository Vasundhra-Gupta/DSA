#include <iostream>
using namespace std;
#include <queue>

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};



TreeNode *levelOrderTraveral(TreeNode *root)
{
    if (root == NULL)
    {
        cout << "Empty Tree" << endl;
        return NULL;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            cout << temp->val << " ";
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

// inorder successor
TreeNode *findMin(TreeNode *root)
{
    if (root->left == NULL)
        return root;
    findMin(root->left);
    // while(root!=NULL){
    //     root= root->left;
    // }
}

TreeNode *deleteNode(TreeNode *root, int val)
{
    if (root == NULL)
        return NULL;
    if (val < root->val)
    {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->val)
    {
        root->right = deleteNode(root->right, val);
    }
    else
    {
        if (!root->left && !root->right)
        {
            delete root;
            root = NULL;
        }
        else if (!root->left)
        {
            TreeNode *temp = root;
            root = root->right;
            delete temp;
        }
        else if (!root->right)
        {
            TreeNode *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            TreeNode *temp = findMin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);//sub case of no child node.
        }
    }
    return root;
}

int main()
{
    TreeNode *root = new TreeNode(80);
    root = create(root);
    levelOrderTraveral(root);
    cout << "\nEnter node to be deleted:" << endl;
    int val;
    cin >> val;
    root = deleteNode(root, val);
    cout << "After Deletion:" << endl;
    levelOrderTraveral(root);
    return 0;
}