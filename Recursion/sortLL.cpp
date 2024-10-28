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

Node* midOfLL(Node* head){
    Node* fast = head;
    Node* slow = head;
    while(fast!=NULL && fast->next!= NULL){
        fast= fast->next;
        if(fast->next!=NULL){
            fast= fast->next;
        }
        slow= slow->next;
    }
    return slow;
}

Node* mergeLL(Node* head1, Node* head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    if(head1->data < head2->data){
        head1->next = mergeLL(head1->next, head2);
        return head1;
    }else{
        head2->next = mergeLL(head1, head2->next);
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

Node* sortLinkedList(Node* head){
    if(head==NULL){
        cout<<"Empty LL\n";
    }
    if(head->next== NULL){
        return head;
    }

    Node* fast = head;
    Node* slow = head;
    Node* prev = NULL;
   while(fast->next!=NULL){
        fast= fast->next;
        if(fast->next!=NULL){
            fast= fast->next;
        }
        prev = slow;
        slow= slow->next;
    }
    Node* mid= slow;
    prev->next = NULL;
   
    cout<<"data at mid "<<mid->data<<endl;
    display(head);
    display(mid);

    Node* left = sortLinkedList(head);
    Node* right = sortLinkedList(mid);
    mergeLL(left, right);
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

    head= sortLinkedList(head);
    display(head);

    Node* middle = midOfLL(head);
    cout<<"The middle of LL is "<<middle->data<<endl;
    return 0;
}