#include <iostream>
#include <queue>
using namespace std;

class TreeNode
{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        this->right = NULL;
        this->left = NULL;
    }
};

TreeNode *create(TreeNode *root)
{
    cout << "current node " << root->val << endl;
    if (root->left)
    {
        create(root->left);
    }
    else
    {
        cout << "Enter left child of " << root->val << endl;
        int val;
        cin >> val;
        if (val != -1)
        {
            root->left = new TreeNode(val);
            create(root->left);
        }
    }

    if (root->right)
    {
        create(root->right);
    }
    else
    {
        cout << "Enter right child of " << root->val << endl;
        int val;
        cin >> val;
        if (val != -1)
        {
            root->right = new TreeNode(val);
            create(root->right);
        }
        //else just move to right na😉
    }
    return root;
}

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

int maxDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    return max(leftHeight, rightHeight)+1;
}

int main()
{
    TreeNode *root = new TreeNode(33);
    root = create(root);
    levelOrderTraveral(root);
    int height = maxDepth(root);
    cout<<"The maximum depth or height of tree is "<<height<<endl;
    return 0;
}