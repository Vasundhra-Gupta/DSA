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

Node* reverseLinkedList(Node* head){
    if(head->next == NULL){
        return head;
    }
    Node* newHead= reverseLinkedList(head->next);
    head->next->next= head;
    head->next = NULL;
    return newHead;
}

void display(Node * head){
    Node* current = head;
    while(current!= NULL){
        cout<<current->data<<"\t";
        current = current->next;
    }
    cout<<endl;
}

int main()
{
    Node* head = NULL;
    head = insertAtHead(head, 12);
    head = insertAtHead(head, 45);
    head = insertAtHead(head, 56);
    head = insertAtHead(head, 78);
    head = insertAtHead(head, 90);
    head = insertAtHead(head, 23);
    head = insertAtHead(head, 67);
    display(head);

    head= reverseLinkedList(head);
    display(head);
    return 0;
}