#include <iostream>
using namespace std;

#define MAX 5  // Maximum size of the queue

class Queue {
private:
    int arr[MAX];
    int front, rear, size;

public:
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    // Check if queue is full
    bool isFull() {
        return size == MAX;
    }

    // Check if queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Enqueue operation
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot insert " << value << endl;
            return;
        }
        rear = (rear + 1) % MAX; // Circular increment
        arr[rear] = value;
        size++;
        cout << value << " enqueued\n";
    }

    // Display queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % MAX] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.enqueue(60); // This will show overflow

    return 0;
}
