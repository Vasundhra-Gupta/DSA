#include <iostream>
using namespace std;

class Tree
{
    int data;
    Tree *parent;
    Tree *left;
    Tree *right;
    Tree(int val)
    {
        this->data = val;
        this->parent = NULL;
        this->left = NULL;
        this->right = NULL;
    }
};

Tree *createTree(Tree *root, int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        Tree *newNode = new Tree(arr[i]);
        if (root == NULL)
        {
            root = newNode;
            return root;
        }
        if (root->left == NULL)
        {
            root->left = newNode;
            newNode->parent = root;
            return root;
        }
        else
        {
            createTree(root->left, val);
        }
        if (root->right == NULL)
        {
            root->right = newNode;
            newNode->parent = root;
            return root;
        }
        else
        {
            createTree(root->left, val)
        }
        createTree(newNode, val);
    }
    return root;
}
int main()
{
    Tree *root = NULL;
    return 0;
}