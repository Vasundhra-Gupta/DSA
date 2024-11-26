#include <iostream>
using namespace std;
//remove an element using front
//add an element using rear
class Queue{
    public: 
    int front;
    int rear;
    int max=5;
    int * arr;
    Queue(int size){
        front= 0;
        rear= -1;
        arr= new int[size];
    }
    int isFull();
    int isEmpty();
    int peek();
    int enqueue(int );
    int dequeue();
    void showQueue();
};
int main(){
    Queue queue(5);
    cout<<"QUEUE FULL: "<<((queue.isFull())? "true" : "false")<<endl;
    cout<<"QUEUE EMPTY: "<<((queue.isEmpty())? "true" : "false")<<endl;
    cout<<"Insertion :"<<endl;
    queue.enqueue(4);
    queue.enqueue(9);
    queue.enqueue(13);
    queue.enqueue(54);
    queue.enqueue(12);
    queue.showQueue();
    cout<<"Deletion: "<<endl;
    queue.dequeue();
    queue.showQueue();
    cout<<"Show peek element"<<endl;
    int peek= queue.peek();
    cout<<peek<<endl;
    return 0;
}

int Queue::isEmpty(){
    if(rear=-1 && front>rear){ //means u deleted element at rare too and emptied complete queue!
        cout<<"Queue is Empty"<<endl;
        return 1;
    }else{
        return 0;
    }
}

int Queue:: isFull(){
    if(front==0 && rear==max-1){
        cout<<"Queue is Full"<<endl;
        return 1;
    }else{
        return 0;
    }
}

int Queue:: peek(){
    if(!isEmpty()){
        return arr[front];
    }else{
        cout<<"Empty Queue"<<endl;
    }
}

int Queue:: enqueue(int x){
    cout<<!isFull()<<"helo";
    if(!isFull()){
        cout<<!isFull();
        rear++;
        arr[rear]= x;
        // arr[++rear] = x;
    }else{
        cout<<"Queue is Full. Can't Insert Elements."<<endl;
    }
    return x;
}

int Queue:: dequeue(){
    int data;
    data= arr[front];
    if(!isEmpty()){
        for(int i=front; i<=rear; i++){
            arr[i]= arr[i+1];
        }
        rear--;
        return data;
    }else{
        cout<<"Queue is Empty. Can't delete elements"<<endl;
    }

}

void Queue:: showQueue(){
    for(int i=front; i<=rear; i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

