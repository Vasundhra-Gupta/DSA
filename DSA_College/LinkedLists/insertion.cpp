#include <iostream>
using namespace std;
//malloc alloacte memory at run time and returns a void pointer to the alo
struct Node{
    int data;
    Node *next;
    int *arr;
};

struct Node *head= NULL;

struct Node *insertAtbeginning(int data){
    struct Node *newNode= (struct Node*) malloc(sizeof(struct Node));
    newNode->data= data;
    if(head==NULL){
        head= newNode;
        return head;
    } 
    newNode->next= head;
    head= newNode;
    return head;
}

struct Node *insertAtend(int data){
    struct Node *temp = head;
    struct Node *newNode= (struct Node*) malloc(sizeof(struct Node));
    if(head== NULL){
        head= newNode;
    }
    while(temp->next!= NULL){
        temp= temp->next;
    }
    temp->next= newNode;
    newNode->next = NULL;
    return head;
}

void display(struct Node *head){
    if(head==NULL){
        cout<< "Empty LinkedList"<<"\t";
    }
    struct Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data;
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    struct Node *head= insertAtbeginning(23);
    insertAtbeginning(14);
    cout<<"head at "<<head->data<<endl;
    display(head);
    insertAtEnd(27);

    return 0;
}