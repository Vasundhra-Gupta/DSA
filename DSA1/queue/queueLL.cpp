#include <iostream>
using namespace std;

// Node class to represent each element in the queue (linked list)
class Node {
public:
    int data;   // Data of the node
    Node* next; // Pointer to the next node in the queue

    // Constructor to initialize the node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Queue class using Linked List
class Queue {
private:
    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue

public:
    // Constructor to initialize the queue
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue operation: Adds an element to the rear of the queue
    void enqueue(int data) {
        Node* newNode = new Node(data);  // Create a new node with given data
        if (rear == nullptr) {
            // If the queue is empty, both front and rear will point to the new node
            front = rear = newNode;
        } else {
            // Add the new node at the rear and update rear pointer
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued " << data << " to the queue" << endl;
    }

    // Dequeue operation: Removes and returns the front element from the queue
    int dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;  // Return -1 to indicate that the queue is empty
        }
        Node* temp = front;         // Store the current front node
        int dequeuedData = front->data; // Get the data from the front node
        front = front->next;        // Move the front pointer to the next node

        // If the queue is now empty, update the rear pointer to nullptr
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;                // Free the memory of the dequeued node
        return dequeuedData;        // Return the dequeued data
    }

    // Peek operation: Returns the front element without removing it
    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return -1;  // Return -1 if queue is empty
        }
        return front->data;  // Return the data at the front of the queue
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Display the queue elements
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "None" << endl;
    }
};

// Driver code to demonstrate queue operations
int main() {
    Queue queue;

    // Enqueue elements to the queue
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    
    // Display the queue
    queue.display();

    // Dequeue an element from the queue
    int dequeuedElement = queue.dequeue();
    cout << "Dequeued element: " << dequeuedElement << endl;

    // Display the queue after dequeuing
    queue.display();

    // Peek the front element of the queue
    int frontElement = queue.peek();
    cout << "Front element: " << frontElement << endl;

    // Check if the queue is empty
    cout << "Is the queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;

    // Dequeue all elements to empty the queue
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    // Display the queue after all elements are dequeued
    queue.display();
    
    // Check if the queue is empty
    cout << "Is the queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}