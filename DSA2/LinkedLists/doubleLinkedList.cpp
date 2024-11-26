#include <iostream>
using namespace std;
int arr[] = {3, 6, 4, 8, 0, 2, 5};
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
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
    display(head);
    return head;
}
Node *insertAtHead(Node *&head, int val)
{
    Node *temp = new Node(val);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    display(head);
    return head;
}
Node *insertAtTail(Node *&head, int val)
{
    Node *current = head;
    Node *temp = new Node(val);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
        temp->prev = current;
        temp->next = NULL;
    }
    display(head);
    return head;
}
Node *insertAtPos(Node *&head, int val, int pos)
{
    Node *temp = new Node(val);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        Node *current = head;
        int cur_pos = 1;
        while (cur_pos != pos)
        {
            current = current->next;
            cur_pos++;
        }
        temp->next = current->next;
        temp->prev = current;
        current->next = temp;
        current = temp;
        // temp->prev=current->prev;
        // temp->next= current->prev->next;
        // current->next=temp;
        // current->prev->next=temp;
        // current=temp;
    }
    display(head);
    return head;
}
Node *deleteAtPos(Node *&head, int pos){
    Node *current= head;
    int curr_pos= 1;
    while(curr_pos!= pos-1){
        current = current->next;
        curr_pos++;
    }
    Node *del= current->next;
    current->next = current->next->next;
    current->next->next->prev= current;
    free(del);
    display(head);
    return head;
}
Node *reverseDLL(Node *&head){
    Node* current= head;
    while(current!= NULL){
        Node *last= current->prev;
        current->prev = current->next;
        current->next = last;
        current = current->prev;
    
    }
    cout<<"out"<<endl;
    cout<<head->data;
    display(head);
    return head;
}
int main()
{
    Node *head = convertArr2DLL();
    insertAtHead(head, 100);
    insertAtTail(head, 123);
    insertAtPos(head, 143, 3);
    deleteAtPos(head, 3);
    reverseDLL(head);
    return 0;
}