//Create an avl tree and Insertion and deletion in AVL Tree.

//AVL TREE
#include <iostream>
using namespace std;

class Node{
    public:
    int data, height;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->height = 0;
        this->left = NULL;
        this->right = NULL;
    }
};

int getHeight(Node* root){
    if(root == NULL) return -1;
    return 1+ max(getHeight(root->left), getHeight(root->right));
}

int getBalance(Node* root){
    return getHeight(root->left) - getHeight(root->right);
}

Node* findMin(Node* root){
    if(root->left == NULL) return root;
    root = findMin(root->left);
    return root;
}

Node* rightRotation(Node* root){
    Node* child = root->left;
    Node* childRight = child->right;
    child->right = root;
    root->left = childRight;
    root->height = getHeight(root);
    child->height = getHeight(child);
    return child;
}

Node* leftRotation(Node* root){
    Node* child = root->right;
    Node* childLeft = child->left;
    child->left = root;
    root->right = childLeft;
    root->height = getHeight(root);
    child->height = getHeight(child);
    return child;
}
Node* insertInAVLTree(Node* root, int val){
    //First insert
    if(root == NULL){
        return new Node(val);
    }

    if(val<root->data){
        root->left = insertInAVLTree(root->left, val);
    }else if(val>root->data){
        root->right = insertInAVLTree(root->right, val);
    }else{
        return root; //no duplicates.
    }

    //And update height and check balance and apply suitable rotation!
    root->height = getHeight(root);

    int balance = getHeight(root->left) - getHeight(root->right);

    if(balance>1 && val<root->left->data){
        return rightRotation(root);
    }else if(balance>1 && val>root->left->data){
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }else if(balance<-1 && val>root->right->data){
        return leftRotation(root);
    }else if(balance<-1 && val<root->right->data){
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }else{
        return root;
    }
}

Node* deleteInAVLTree(Node* root, int val){
    if(root==NULL) return NULL;
    if(val< root->data){
        root->left =  deleteInAVLTree(root->left, val);
    }else if(val> root->data){
        root->right =  deleteInAVLTree(root->right, val);
    }else{
        if(root->right==NULL && root->left == NULL){
            delete root;
            root = NULL;
            return root;
        }else if(root->right == NULL){
            Node* temp = root;
            root = root->left;
            delete temp;
            return root;
        }else if(root->left == NULL){
            Node* temp = root;
            root = root->right;
            delete temp;
            return root;
        }else{
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteInAVLTree(root->right , temp->data);
        }
    }
    if(getBalance(root)>1){
        if(getBalance(root->left)>=0)
            return rightRotation(root);
        else   
            root->left = leftRotation(root->left);
            return rightRotation(root);
    }else if(getBalance(root)<-1){
        if(getBalance(root->right)>=0)
            return leftRotation(root);
        else
            root->right = rightRotation(root->right);
            return leftRotation(root);
    }else{
        return root;
    } 
}

Node* inOrderTraversal(Node* root){
    if(root==NULL) return NULL;
    inOrderTraversal(root->left);
    cout<<root->data<<"\t";
    inOrderTraversal(root->right);
    return root;
}

int main(){
    Node* root = NULL;
    root = insertInAVLTree(root, 34);
    root = insertInAVLTree(root, 72);
    root = insertInAVLTree(root, 98);
    root = insertInAVLTree(root, 65);
    root = insertInAVLTree(root, 42);
    root = insertInAVLTree(root, 12);
    root = insertInAVLTree(root, 34);
    root = insertInAVLTree(root, 87);
    inOrderTraversal(root);
    cout<<endl;
    root = deleteInAVLTree(root, 65);
    inOrderTraversal(root);
    return 0;
}