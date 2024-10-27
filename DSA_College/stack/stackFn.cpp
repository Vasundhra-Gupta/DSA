#include "stackFn.h"
#include <iostream>
using namespace std;
#define STACKFN_H
#define size 100
   namespace stack_functions
   {
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
   }
   