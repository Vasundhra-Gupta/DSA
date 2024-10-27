#ifndef STACKFN_H
#define STACKFN_H
# define size 100
namespace stack_functions{
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
}
#endif