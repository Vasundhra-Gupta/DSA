#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

int arr[] = {1, 2, 3, 4, 5, 6, 7};
Node *convertArr2DLL()
{
    Node *head = new Node(arr[0]);
    Node *current = head;
    for (int i = 1; i < 7; i++)
    {
        Node *temp = new Node(arr[i]);
        current->next = temp;
        temp->prev = current;
        current = temp;
    }
    return head;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Node *reverse(Node *head){
//     Node* temp = head;
//     while(temp-!=NULL){
//         Node* store= temp->next;//can't store like this , bcz we dont have any track for prev element and when store/temp reaches null we are not able to get head but NULL's prev is nothing. And when temp->next = NULL (if we use this condition), then we don't have set temp->next as temp->prev for last round,SO BETTER TO STORE temp->prev
//         temp->next= temp->prev;
//         temp->prev= store;
//         temp= store;
//     }
//     return temp->prev;
// }

// Node *reverse(Node *head){
//     Node* temp = head;
//     while(temp-!=NULL){
//         Node* store= temp->prev;
//         temp->prev= temp->next;
//         temp->next= store;
//         temp= temp->next;//but for moving forward we need next pointer so store both;
//     }
//     return temp->prev;
// }

Node *reverse1(Node *head){
    Node* temp = head;
    Node* prev= NULL;
    while(temp!=NULL){
        prev= temp->prev;
        temp->prev= temp->next;
        temp->next= prev;
        temp= temp->prev;
    }
    return prev->prev;//bcz now temp is null but prev still didnt set to the last one, so prev->next is the last one
}

Node *reverse2(Node *head){
    Node* temp = head;
    Node* forward= NULL;
    Node* prev= NULL;
    while(temp!=NULL){
        forward= temp->next;
        temp->next= temp->prev;
        temp->prev= forward;
        prev= temp; // just to keep track on index!!
        temp= forward;
    }
    return prev;
}

int main()
{
    Node *head = convertArr2DLL();
    display(head);
    cout << "head =" << head->data << endl;

    head= reverse1(head);
    display(head);

    head= reverse2(head);
    display(head);
    return 0;
}