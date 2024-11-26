#include <iostream>
using namespace std;

class Queue{
    public: 
    int front;
    int rear;
    int max=5;
    int * arr;
    Queue(int size){
        front= -1;
        rear= -1;
        arr= new int[size];
    }
    bool isFull();
    bool isEmpty();
    int peek();
    int enqueue(int);
    int dequeue();
    void showQueue();
};

int main(){

    
    return 0;
}

bool Queue::isEmpty(){
    if(front == rear == -1 || front>rear){
        cout<<"Queue Underflow"<<endl;
        return 1;
    }else{
        return 0;
    }
}

bool Queue::isFull(){
    if(front==0 && rear==max-1){
        cout<<"Queue Overflow"<<endl;
       return 1;
    }else{
        return 0;
    }
}

int Queue::peek(){
    if(!isEmpty()){
        return arr[front];
    }
}

int Queue::enqueue(int data){
    if(!isFull()){
        if(rear== front==-1){
            front=0;
            arr[++rear] = data;
        }else{
            arr[++rear] = data;
        }
        return data;
    }else{
        cout<<"Can't insert elements"<<endl;
        return -1;
    }
}

int Queue::dequeue(){
    if(!isEmpty()){
        
    }
}