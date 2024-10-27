#include <iostream>
using namespace std;
class Stack
{
public:
    int top;
    int *arr;
    int size;
    Stack(int s)
    {
        size = s;
        top = -1;
        arr = new int[size];
    }

    int push(int data)
    {
        if (top == size - 1)
        {
            cout << "Stack overflow ☹" << endl;
        }
        else
        {
            top = top + 1;
            arr[top] = data;
        }
        return data;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow 😔" << endl;
        }
        else
        {
            int d = arr[top];
            top = top - 1;
            return d;
        }
    }
    void showStack()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }
};

void copyStack(Stack stack1, Stack &stack2)
{
    int stack1Top = stack1.top;
    for (int i = 0; i <= stack1Top; i++)
    {
        stack2.push(stack1.arr[i]);
        stack1.pop();
    }
}
int main()
{
    Stack stack1(5);
    stack1.push(32);
    stack1.push(56);
    stack1.push(23);
    stack1.push(67);
    stack1.push(19);
    stack1.showStack();

    Stack stack2(5);

    copyStack(stack1, stack2);
    cout << "Stack1" << endl;
    stack1.showStack();
    cout << "Stack2" << endl;
    stack2.showStack();

    return 0;
}