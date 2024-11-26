#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
int arr[] = {3, 6, 4, 8, 0, 2, 5};
Node *convertArr2LL()
{
    Node *head = new Node(arr[0]);
    Node *current = head;
    for (int i = 1; i < 7; i++)
    {
        Node *temp = new Node(arr[i]);
        current->next = temp;
        current = temp;
    }
    return head;
}

void display(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << "->";
        current = current->next;
    }
    cout << endl;
}
Node *insertAtHead(Node *&head, int val)
{
    Node *temp = new Node(val);
    if (head == NULL)
    {
        head = temp;
    }
    temp->next = head;
    head = temp; // don't write temp= head, its problamatic/wrong assignment
    return head;
}
Node *insertAtTail(Node *&head, int val)
{
    Node *current = head;
    Node *temp = new Node(val);
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = temp;
    temp->next = NULL;
    return head;
}
Node *insertAtPos(Node *&head, int val, int pos)
{
    Node *current = head;
    Node *temp = new Node(val);
    int cur_pos = 1;
    while (cur_pos != pos - 1)
    {
        current = current->next;
        cur_pos++;
    }
    temp->next = current->next;
    current->next = temp;
    return head;
}
Node *insertBeforeVal(Node *&head, int val, int beforeVal)
{
    Node *current = head;
    Node *temp = new Node(val);
    while (current->next->data != beforeVal)
    {
        current = current->next;
    }
    temp->next = current->next;
    current->next = temp;
    return head;
}
Node *deleteAtHead(Node *&head)
{
    Node *del = head;
    head = del->next;
    free(del);
    return head;
}
Node *deleteAtTail(Node *&head)
{
    Node *current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    Node *del = current->next;
    current->next = NULL;
    free(del);
    return head;
}
Node *deleteAtPos(Node *&head, int pos)
{
    Node *current = head;
    int cur_pos = 1;
    while (cur_pos != pos - 1)
    {
        current = current->next;
    }
    Node *del = current->next;
    current->next = current->next->next;
    free(del);
    return head;
}
Node *deleteAfterVal(Node *&head, int val)
{
    Node *current = head;
    while (current->data != val)
    {
        current = current->next;
    }
    Node *del = current->next;
    current->next = current->next->next;
    free(del);
    return head;
}
Node *updateValAtPos(Node *head, int newVal, int pos)
{
    Node *current = head;
    int cur_pos = 1;
    while (cur_pos != pos)
    {
        current = current->next;
        cur_pos++;
    }
    current->data = newVal;
}
Node *updateValAtVal(Node *head, int newVal, int val)
{
    Node *current = head;
    while (current->data != val)
    {
        current = current->next;
    }
    current->data = newVal;
    return head;
}
void SearchVal(Node *head, int val)
{
    Node *current = head;
    int cur_pos = 1;
    bool found;
    while (current->next != NULL)
    {
        if (current->data == val)
        {
            found = true;
            cout << "The element you searched is at position " << cur_pos << endl;
        }
        current = current->next;
        cur_pos++;
    }
    if (!found)
    {
        cout << "No. not found" << endl;
    }
}
Node *reverseSLL(Node *head)
{
    // Node *curr = head;
    // Node *prev = NULL;
    // while (curr != NULL)
    // {
    //     Node *forward = curr->next;
    //     curr->next = prev;
    //     prev = curr;
    //     curr = forward;
    // }
    // return prev;

    if(head->next==NULL) return head;
    Node* head2 = reverseSLL(head->next);
    head->next->next=head;
    head->next = NULL;
    return head2;
}

int main()
{
    // Converting an array to linked list
    cout<<"Linked Lists"<<endl;
    Node *head = convertArr2LL();
    display(head);
    // 3->6->4->8->0->2->5->(last arrow sign is bcz we are after last node and not at it)

    // Insertion at head
    cout<<"Insert At head"<<endl;
    insertAtHead(head, 100);
    display(head);

    // Insertion At Tail
     cout<<"Insert At Tail"<<endl;
    insertAtTail(head, 200);
    display(head);

    // Insert At specified
     cout<<"Insert At specified location"<<endl;
    insertAtPos(head, 143, 2);
    display(head);

    // Insert before value
     cout<<"Insert Before value"<<endl;
    insertBeforeVal(head, 99, 0);
    display(head);

    // Delete at begin
     cout<<"Delete At head"<<endl;
    deleteAtHead(head);
    display(head);

    // Delete at tail
     cout<<"Delete At Tail"<<endl;
    deleteAtTail(head);
    display(head);

    // Delete at specified position
     cout<<"Delete At specified location"<<endl;
    deleteAtPos(head, 2);
    display(head);
    // Delete after a value
     cout<<"Delete after a value"<<endl;
    deleteAfterVal(head, 99);
    display(head);

    // Update value at specifies position
     cout<<"Update value At specified location"<<endl;
    updateValAtPos(head, 45, 3);
    display(head);

    // Update value in place of other value
     cout<<"Update value in place of other value"<<endl;
    updateValAtVal(head, 22, 2);
    display(head);

    // Search an element
    SearchVal(head, 22);

    return 0;
}