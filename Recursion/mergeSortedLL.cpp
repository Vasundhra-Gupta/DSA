#include <iostream>
using namespace std;

class Node
{
    public: 
    int data;
    Node *next;
    int *arr;
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

Node *insertAtHead(Node *head, int val)
{
    Node *current = head;
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    newNode->next = head;
    head = newNode;
    return head;
}

Node* mergeLinkedList(Node* head1, Node* head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }

    if(head1->data < head2->data){
        head1->next = mergeLinkedList(head1->next, head2);
        return head1;
    }else{
        head2->next = mergeLinkedList(head1, head2->next);
        return head2;
    }
}

void display(Node * head){
    Node* current = head;
    while(current!= NULL){
        cout<<current->data<<"\t";
        current = current->next;
    }
    cout<<endl;
}
int main(){
    Node* head1 = NULL;
    head1 = insertAtHead(head1, 90);
    head1 = insertAtHead(head1, 78);
    head1 = insertAtHead(head1, 56);
    head1 = insertAtHead(head1, 45);
    head1 = insertAtHead(head1, 12);
    display(head1);

    Node* head2 = NULL;
    head2 = insertAtHead(head2, 72);
    head2 = insertAtHead(head2, 65);
    head2 = insertAtHead(head2, 52);
    head2 = insertAtHead(head2, 39);
    head2 = insertAtHead(head2, 26);
    head2 = insertAtHead(head2, 13);
    display(head2);

    Node* head= mergeLinkedList(head1, head2);
    display(head);
    return 0;
}