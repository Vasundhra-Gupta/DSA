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

class Stack
{
public:
    Node *head;
    Stack()
    {
        this->head = NULL;
    }
    void showStack();
    int push(int);
    int pop();
    bool isEmpty();
    // bool isFull(Node *&);
};

int main()
{
    Stack stack;
    stack.push(12);
    stack.push(24);
    stack.push(48);
    stack.push(13);
    stack.push(89);
    stack.showStack();
    stack.pop();
    stack.showStack();
    stack.pop();
    stack.showStack();
    return 0;
}

bool Stack ::isEmpty()
{
    if (head == NULL)
    {
        cout << "stack empty:" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

void Stack ::showStack()
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << "\t";
        current = current->next;    
    }
    cout<<endl;
}

int Stack ::push(int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
        return data;
    }
    temp->next = head;
    head = temp;

    return data;
}

int Stack ::pop()
{
    if (isEmpty())
    {
        return -1;
    }
    Node *del = head;
    head = del->next;
    free(del);
    return del->data;
}