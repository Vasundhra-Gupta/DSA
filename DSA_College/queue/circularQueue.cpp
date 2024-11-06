#include <iostream>
using namespace std;
class Queue
{
public:
    int front;
    int rear;
    int *arr;
    int size;
    Queue(int size)
    {
        front = 0;
        rear = -1;
        arr = new int[size];
    }
    int isFull();
    int isEmpty();
    int peek();
    int enqueue(int);
    int dequeue();
    void showQueue();
};

int main()
{
    Queue queue(5);
    cout << "QUEUE FULL: " << ((queue.isFull()) ? "true" : "false") << endl;
    cout << "QUEUE EMPTY: " << ((queue.isEmpty()) ? "true" : "false") << endl;
    cout << "Insertion :" << endl;
    queue.enqueue(4);
    queue.enqueue(9);
    queue.enqueue(13);
    queue.enqueue(54);
    queue.enqueue(12);
    queue.showQueue();
    cout << "Deletion: " << endl;
    queue.dequeue();
    queue.showQueue();
    cout << "Show peek element" << endl;
    int peek = queue.peek();
    cout << peek << endl;
    return 0;
    return 0;
}

int Queue::isEmpty()
{
    if (front = -1 || front > rear)
    {
        cout << " Queue Underflow " << endl;
        return 1;
    }
    else
        return 0;
}

int Queue::isFull()
{
    if ((front == 0 && rear == size - 1) || rear == front - 1)
    {
        cout << " Queue Overflow " << endl;
        return 1;
    }
    else
        return 0;
}

void Queue::showQueue()
{
    if (!isEmpty())
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }
    else
        cout << "Queue is empty" << endl;
}

int Queue:: enqueue(int x){
    if(!isFull()){
        if(front==-1 && rear==-1){
            front=0;
            rear=0;
        } else if(front!=-1){
            rear=0; 
        }
        arr[++rear] = x;
    }else{
        cout<<"Queue is Full. Can't Insert Elements."<<endl;
    }
    return x;
}

int Queue:: dequeue(){
    if(!isEmpty()){
        front++;
        int d= arr[front];
        for(int i=front; i<=rear; i++){
            arr[i]=a[i+1];
        }
    }else{
        cout<<"Stack Underflow"<<endl;
    }
    return d;
}
