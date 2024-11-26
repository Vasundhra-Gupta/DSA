#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node* insertAtHead(Node* head, int val){
    Node* temp = new Node(val);
    if(head==NULL){
        head = temp;
        return head;
    }
    temp->next =head;
    head= temp;
    return head;
}

Node* removeDuplicates(Node* head){
    Node* current = head;
    Node* prev = NULL;
    while(current!= NULL){
        Node* old = head;
        while(old!= current && old->data != current->data){
            old = old->next;
        }
        if(old!= current && old->data == current->data){
            Node * del = current;
            prev->next = current->next;
            current = del->next;
            free(del);
        }else{
            prev = current;
            current= current->next; 
        }
    }
    return head;
}

Node* showLL(Node* head){
    Node* current = head;
    if (head== NULL) return NULL;
    while(current!=NULL){
        cout<<current->data<<"\t";
        current= current->next;
    }
    cout<<endl;
    return head;
}

int main(){
    Node* head = NULL;
    head= insertAtHead(head, 2);
    head= insertAtHead(head, 4);
    head= insertAtHead(head, 2);
    head= insertAtHead(head, 5);
    head= insertAtHead(head, 5);
    head= insertAtHead(head, 26);
    head= insertAtHead(head, 2);

    showLL(head);
    cout<<"New Linked Lists"<<endl;
    head = removeDuplicates(head);

    showLL(head);

    return 0;
}