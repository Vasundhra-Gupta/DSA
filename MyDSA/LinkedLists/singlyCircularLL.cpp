// Will use pointer to last node here bcz we can keep track of what's there in last's next but in head's prev we would woud have to traverse complete LL to track last node
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void display(Node *&last)
{
    if (last == NULL)//last
    {
        cout << "Empty List" << endl;
    }
    Node *current = last->next; // head
    do
    {
        cout << current->data << " <-> ";
        current = current->next;
    } while (current != last->next);
    cout << endl;
}

Node *insert(Node *&last, int val)
{
    Node *temp = new Node(val);
    if (last == NULL)
    {
        last = temp;
        last->next = last; // self pointing node
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
    }
    return last;
}

Node *insertAtPos(Node *&last, int val, int pos)
{
    Node *temp = new Node(val);
    if (last == NULL)
    {
        last = temp;
        last->next = last; // self pointing node
        return last;
    }
    int curr_pos = 1;
    Node *current = last->next;
    while (curr_pos != pos - 1)
    {
        current = current->next;
        curr_pos++;
    }
    temp->next = current->next;
    current->next = temp;
    current = temp;
    return last;
}

Node *deleteAtPos(Node *&last, int pos)
{
    Node *current= last->next;
    int curr_pos=1;
    while(curr_pos!= pos-1){//at pos
        current= current->next;
        curr_pos++;
    }
    Node *del= current->next;
        current->next= del->next;
        free(del);
    return last;
}
int main()
{
    Node *last = NULL;
    insert(last, 27);
    display(last);
    insert(last, 143);
    display(last);
    insert(last, 142);
    display(last);
    insert(last, 141);
    display(last);
    insertAtPos(last, 111, 2);
    display(last);
    deleteAtPos(last, 3);
    display(last);
    deleteAtPos(last, 3);
    display(last);
    insertAtPos(last, 143143143, 2);
    display(last);
    return 0;
}