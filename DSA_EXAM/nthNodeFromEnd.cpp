#include <iostream>
#include "headers/node.h"

using namespace std;

//Find the value of nth node from the end of the Linked list.
//TC - O(n + n-c)
//SC - O(1)
Node* nthNodeFromEnd(Node* head , int n){
    Node* current = head;
    int c =0;
    while(current!=NULL){
        c++;
        current = current->next;
    }
    current = head;
    int pos = 0;
    while(pos != c-n){
        pos++;
        current = current->next;
    }
    return current;//bcz current is already to next so it it will give a node ahead of c-n
}

//Remove nth Node From the end
//TC - O(n + n-c)
//TC - O(n) in best case when 1 node has to be removed!!
//SC - O(1)
Node* removeNthNodeFromEnd(Node* head, int n){
    int c =0;
    Node* current = head;
    while(current!=NULL){
        c++;
        current = current->next;
    }
    //When first node is to be removed.
    if(n==c){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int pos = 0;
    current = head;
    while(pos != c-n-1){
        pos++;
        current = current->next;
    }
    Node* del = current->next;
    current->next = current->next->next;
    del->next = NULL;
    delete del;
    return head;
}

int main(){
    Node* head = NULL;
    int arr[] = {23, 45, 67, 89, 21}; 
    int size =sizeof(arr)/sizeof(arr[0]);
    head = makeALinkedList(head, arr, size);
    displayList(head);
    int n;
    cout<<"Enter the value of n:"<<endl;
    cin>>n;
    Node* nth = nthNodeFromEnd(head, n);
    cout<<"The value of "<<n<<"th node from the end of LL is "<<nth->data<<endl;
    head = removeNthNodeFromEnd(head, n);
    displayList(head);
    return 0;
}