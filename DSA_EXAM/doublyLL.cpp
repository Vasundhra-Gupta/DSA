#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        this->data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

Node* insertAtHead(Node* head, int val){
    Node* temp = new Node(val);
    if(head == NULL){
        head = temp;
        return head;
    }
    temp->next = head;
    head->prev = temp;
    temp->prev = NULL;
    head= temp;
    return head;
}

//🔴Delete in begin prob(infinite loop, don't know why)
Node* deleteNode(Node* head, int val){
    if(head==NULL){
        return head;
    }

    if(head->data == val){
        Node* temp = head;
        head = head->next;
        if(head!=NULL){
            head->prev = NULL;
        }
        delete temp;
        return head;
    }

    Node* current = head;
    while(current!=NULL){
        if(current->data == val){
            if(current->next == NULL){
                current->prev->next = NULL;
            }else{
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            return head;
        }
        current = current->next;
    }
    cout<<"This node doesn't exists.\n";
    return head;
}

Node* displayLinkedList(Node* head){
    Node* current = head;
    while(current!=NULL){
        cout<<current->data<<"\t";
        current = current->next;
    }
    cout<<endl;
    return head;
}

bool checkPalindrome(Node* head){
    if(head==NULL){
        cout<<"The linked list is empty."<<endl;
        return true;
    }

    if(head->next == NULL){
        return true;
    }

    Node* start = head;
    Node* end = head;

    while(end->next!=NULL){
        end= end->next;
    }

    while(start!=end && start->prev!= end){
        if(start->data != end->data){
            return false;
        }
        start =start->next;
        end = end->prev;
    }
    return true;
}

int main(){
    Node* head = NULL;
    head = insertAtHead(head, 89);
    head = insertAtHead(head, 23);
    head = insertAtHead(head, 43);
    head = insertAtHead(head, 43);
    head = insertAtHead(head, 23);
    head = insertAtHead(head, 23);
    head = insertAtHead(head, 89);
    // displayLinkedList(head);
    // deleteNode(head, 89);
    displayLinkedList(head);
    deleteNode(head, 23);
    // displayLinkedList(head);
    // deleteNode(head, 29);
    displayLinkedList(head);

    if(checkPalindrome(head)){
        cout<<"Palindrome"<<endl;
    }else{
        cout<<"Not Palindrome"<<endl;
    }
    return 0;
}
