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

Node* preOrderIterative(Node* root){
    stack <Node*> st;
    if(root==NULL){
        return NULL;
    }
    st.push(root);
    // vector <int> arr;
    while(!st.empty()){
        Node* temp = st.top();
        // arr.push_back(temp->data);
        cout<<temp->data<<" ";
        st.pop();

        if(temp->right){
            st.push(temp->right);
        }

        if(temp->left){
            st.push(temp->left);
        }
    }

    return root;
}
int main(){
    Node* root= NULL;
    root = createTree(root);
    preOrderIterative(root);
    return 0;
}