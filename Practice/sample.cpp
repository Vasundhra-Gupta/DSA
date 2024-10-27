#include<iostream>
#include<cmath>
using namespace std;

class Stack {
    public:
    int size;
    int top;
    char * arr;

    Stack(int s) {
        this -> size = s;
        this -> top = -1;
        this -> arr = new char[s];
    }

    void push(int e) {
        if(top == size - 1) {
            cout << "stack overflow" << endl;
        }
        else arr[++top] = e;
    }

    char pop() {
        if(top == -1) {
            cout << "stack underflow" << endl;
            return '0';
        }
        return arr[top--];
    }

    char peek() {
        if(top == -1) {
            return '0';
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1 ? true : false;
    }
};

int precedence(char c) {
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return 0;
}
string convertToPostfix(string infix)
{
    int i = 0;
    int l = infix.length();
    Stack s(l);
    string postfix;
    while (i < l)
    {
        if (infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (s.peek() != '(')
            {
                postfix += s.pop();
            }
            s.pop();
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            if (s.peek() == '(')
            {
                s.push(infix[i]);
            }
            else
            {
                while (precedence(s.peek()) >= precedence(infix[i]))
                {
                    postfix += s.pop();
                }
                s.push(infix[i]);
            }
        }
        else
        {
            postfix += infix[i];
        }
        i++;
    }
    // pop any remaning elements in the stack
    while (!s.isEmpty())
    {
        postfix += s.pop();
    }
    return postfix;
}

int main () {
    string infix = "((2+7)*3-2)/5";
    string postfix;
    
    postfix = convertToPostfix(infix); 

    cout << postfix << endl;

    return 0;
}
