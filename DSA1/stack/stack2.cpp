#include <iostream>
// #include "stackFn.h"
// using namespace stack_functions;
using namespace std;
#define size 100

struct Stack{
    int arr[size];
    int top;
};
int initialize(Stack &);
int isFull(Stack&);
int isEmpty(Stack&);
int push(Stack&,int);
int pop(Stack&);
int peek(Stack&);
void showStack(Stack&);

int main(){
    struct Stack stack;
    initialize(stack);
    cout<<"Stack full: "<<(isFull(stack)?"true":"false")<<endl;
    cout<<"Stack empty: "<<(isEmpty(stack)?"true":"false")<<endl;
    push(stack,23);
    push(stack,53);
    push(stack,57);
    push(stack,12);
    push(stack,78);
    push(stack,34);
    push(stack,89);
    showStack(stack);
    cout<<"top element in stack is "<<peek(stack)<<endl;
    pop(stack);
    pop(stack);
    pop(stack);
    cout<<"top element in stack after pop is "<<peek(stack)<<endl;
    cout<<"Stack full: "<<(isFull(stack)?"true":"false")<<endl;
    cout<<"Stack empty: "<<(isEmpty(stack)?"true":"false")<<endl;
    cout<<"Stack is: "<<endl;
    showStack(stack);

    return 0;
}
    //initialize
    int initialize(Stack & stack){
        stack.top=-1;
    }
    // checking if the stack is full
    int isFull(Stack &stack){
        if(stack.top==size-1){
            return 1;
        }else{
            return 0;
        }
    }
    //checking whether stack is empty
    int isEmpty(Stack &stack){
        if(stack.top==-1){
            // cout<<"Stack is Empty"<<endl;
            return 1;
        }else{
            return 0;
        }
    }
    //pushing the elements
    int push(Stack &stack,int data){
        if(!isFull(stack)){
            stack.top= stack.top+1;
            stack.arr[stack.top]=data;
        }else{
            cout<<"Stack is full. Can't insert elements"<<endl;
        }
        return data;//
    }
    //popping elements
    int pop(Stack &stack){
        int d;
        if(!isEmpty(stack)){
            d= stack.arr[stack.top];
            stack.top=stack.top-1;
            return d;
        }else{
            cout<<"Stack is empty. Can't delete elements"<<endl;
            return -1;
        }
    }
    //see top element
    int peek(Stack &stack){
        if(!isEmpty(stack)){
            return stack.arr[stack.top];
        }else{
            cout<<"Stack is empty."<<endl;
        }
    }
    // print the stack elements
    void showStack(Stack &stack){
        if(isEmpty(stack)){
            cout<<"Stack is empty"<<endl;
        }else{
            for(int i=0; i<=stack.top; i++){
                cout<<stack.arr[i]<<endl;
            }
        }
    }