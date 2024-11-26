#include <iostream>
using namespace std;
#include <stack>
#include <vector>

class Node{
    public:
    int data;
    Node* right;
    Node* left;
    Node(int val){
        this->data = val;
        this->right = NULL;
        this->left = NULL;
    }
};

Node* createTree(Node* root){
    cout<<"Enter data:\n";
    int data;
    cin>>data;

    if(data==-1){
        return NULL;
    }
    root = new Node(data);
    cout<<"Enter to insert in left of "<<root->data<<endl;
    root->left= createTree(root->left);
    cout<<"Enter to insert in right of "<<root->data<<endl;
    root->right= createTree(root->right);

    return root;
}

//make temp node that store first ele (root)
//now till stack empty
//if temp exist then push left and shift temp to left
//if temp is null then print top and shift temp to right

Node* inOrderIterative(Node* root){
    stack <Node*> st;
    if(root==NULL){
        return NULL;
    }
    Node * temp;
    temp = root;

    while(true){
        if(temp){
            st.push(temp);
            temp= temp->left;//so that we go to the extreme left
        }
        else{
            if(st.empty()==true) break;//to get out of loop
            temp = st.top();
            cout<<temp->data<<" ";
            st.pop();
            temp = temp->right;
        }
    }
    return root;
}

int main(){
    Node* root= NULL;
    root = createTree(root);
    inOrderIterative(root);
    return 0;
}