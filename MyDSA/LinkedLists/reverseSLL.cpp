#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data= data;
        this->next= NULL;
    }
};
// class Stack{
//     public: 
//     int data;
// }
int arr[] = {3, 6, 4, 8, 0, 2, 5};
Node *convertArr2LL()
{
    Node *head = new Node(arr[0]);
    Node *current = head;
    for (int i = 1; i < 7; i++)
    {
        Node *temp = new Node(arr[i]);
        current->next = temp;
        current = temp;
    }
    return head;
}

void display(Node *&head)
{
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << " <-> ";
        current = current->next;
    }
    cout << endl;
}

Node *reverse(Node *head){
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        Node* store= temp->next;
        temp->next= prev;
        prev= temp;
        temp= store;
    }
    return prev;
}

// recursive
Node* reverse2(Node* head){
    //base case
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* head1= reverse2(head->next);
    head->next->next= head;
    head->next= NULL;
    return head1;
}


int main(){
    Node *head= convertArr2LL();
    display(head);
    head= reverse(head);
    display(head);
    head= reverse2(head);
    display(head);
    return 0;
}