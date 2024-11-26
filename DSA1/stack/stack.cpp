#include <iostream>
using namespace std;
#define size 100
// int stack[size];
// int top=-1

class Stack{
    public:
    int top;
    int* arr;
    public:
    Stack(){
        top=-1;
        arr= new int[size];
    }
    int isFull();
    int isEmpty();
    int push(int);
    int pop();
    int peek();
    void showStack();   
};

int main(){
    Stack stack;
    cout<<"Stack full: "<<(stack.isFull()?"true":"false")<<endl;
    cout<<"Stack empty: "<<(stack.isEmpty()?"true":"false")<<endl;
    stack.push(23);
    stack.push(53);
    stack.push(57);
    stack.push(12);
    stack.push(78);
    stack.push(34);
    stack.push(89);
    stack.showStack();
    cout<<"top element in stack is "<<stack.peek()<<endl;
    stack.pop();
    stack.pop();
    stack.pop();
    cout<<"top element in stack after pop is "<<stack.peek()<<endl;
    cout<<"Stack full: "<<(stack.isFull()?"true":"false")<<endl;
    cout<<"Stack empty: "<<(stack.isEmpty()?"true":"false")<<endl;
    cout<<"Stack is: "<<endl;
    stack.showStack();

    return 0;
}

    // checking if the stack is full
    int Stack:: isFull(){
        if(top==size-1){
            return 1;
        }else{
            return 0;
        }
    }
    //checking whether stack is empty
    int Stack:: isEmpty(){
        if(top==-1){
            // cout<<"Stack is Empty"<<endl;
            return 1;
        }else{
            return 0;
        }
    }
    //pushing the elements
    int Stack:: push(int data){
        if(!isFull()){
            top= top+1;
            arr[top]=data;
        }else{
            cout<<"Stack is full. Can't insert elements"<<endl;
        }
        return data;//
    }
    //popping elements
    int Stack:: pop(){
        int d;
        if(!isEmpty()){
            d= arr[top];
            top=top-1;
            return d;
        }else{
            cout<<"Stack is empty. Can't delete elements"<<endl;
            return -1;
        }
    }
    //see top element
    int Stack:: peek(){
        if(!isEmpty()){
            return arr[top];
        }else{
            cout<<"Stack is empty."<<endl;
        }
    }
    // print the stack elements
    void Stack:: showStack(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
        }else{
            for(int i=0; i<=top; i++){
                cout<<arr[i]<<endl;
            }
        }
    }