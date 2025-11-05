#include <iostream>
using namespace std;

#define MAX 5

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

    bool isFull() { return size == MAX; }
    bool isEmpty() { return size == 0; }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow!\n";
            return;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = value;
        size++;
        cout << value << " enqueued\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }
        cout << arr[front] << " dequeued\n";
        front = (front + 1) % MAX;
        size--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < size; i++)
            cout << arr[(front + i) % MAX] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.display();

    return 0;
}
