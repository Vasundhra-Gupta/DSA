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

bool Queue:: isEmpty(){
    cout<<"Stack Empty"<<endl;
    return (front = -1 && rear = -1 || front >= rear);
}

bool Queue:: isFull(){
    cout<<"Stack Full"<<endl;
    return (front=-1 && rear= size-1);
}

int Queue:: enqueue(int data){
    if(front==-1 && rear==-1){
        rear=0;
        // why front 0
    }
    else rear++;
    arr[rear]= data; 
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

int Queue:: peek(){
    if(!isEmpty())
    return arr[front+1];
    else cout<<"Stack Underflow";
}

void Queue:: showQueue(){
    for(int i=front; i<=rear; i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}