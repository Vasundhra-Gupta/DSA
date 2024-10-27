#include <iostream>
using namespace std;
typedef struct Node{
    int data;
    Node* next;
    int* arr;
} node;

void showLL(node* head){
    node* current = head;
    while(current!= NULL){
        cout<<current->data<<"\t";
        current = current->next;
    }
    cout<<endl;
}
node* insertAtBeginning(node* head, int value){
    node* current = head;
    node* newNode = new node();//malloc was giving wrong answer
    newNode->data= value;
    if(head==NULL){
        head= newNode;
        return head; 
    }
    newNode->next= head;
    head= newNode;
    return head;
}
int main(){
    node* head= NULL;
    head= insertAtBeginning(head, 3);
    head= insertAtBeginning(head, 4);
    head= insertAtBeginning(head, 5);
    head= insertAtBeginning(head, 6);
    head= insertAtBeginning(head, 7);
    showLL(head);
    return 0;
}