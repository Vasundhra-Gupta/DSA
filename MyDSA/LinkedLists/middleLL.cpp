#include <iostream>
using namespace std;

int arr[] = {3, 6, 4, 8, 90, 2, 5};

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

//normal
int midOfLL(Node* head){
    Node* current=head;
    Node* temp= current;
    int cur_pos = 1;;
    while(current->next!=NULL){
        current= current->next;
        cur_pos++;
    }
   
    int mid_pos= 1;
    int mid= int(cur_pos/2 + 1);
    while(mid_pos != mid){
        temp= temp->next;
        mid_pos++;
    }
    cout<<"The middle element is "<<temp->data<<endl;
    return temp->data;
}

//smart approach
int middleOfLL(Node* head){
    Node* slow =head;
    Node* fast= head;
    while(fast->next!=NULL){
        fast= fast->next;
        if(fast!=NULL){
            fast= fast->next;
        }
        slow= slow->next;
    }
    return slow->data;
}

int main(){
    Node* head1= convertArr2LL();
    display(head1);
    midOfLL(head1);
    int mid= middleOfLL(head1);
    cout<<mid<<endl;
    return 0;
}