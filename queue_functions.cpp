#include <iostream>
using namespace std;

#define MAX 10

class Queue {
    int arr[MAX];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // (i) Determine Size of Queue
    int size() {
        if (front == -1) return 0;
        return (rear - front + 1);
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    // (ii) Input Queue (Enqueue)
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    // (iii) Output Queue (Dequeue / Display Queue)
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        int x = arr[front];
        if (front == rear)
            front = rear = -1;
        else
            front++;
        return x;
    }

    // (iv) Split Queue into two queues (Even & Odd)
    void split(Queue &evenQ, Queue &oddQ) {
        for (int i = front; i <= rear; i++) {
            if (arr[i] % 2 == 0)
                evenQ.enqueue(arr[i]);
            else
                oddQ.enqueue(arr[i]);
        }
    }
};


int main() {
    Queue q, evenQ, oddQ;
    int n, x;

    cout << "Enter elements to insert: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.enqueue(x);
    }

    cout << "\nOriginal ";
    q.display();
    cout << "Size of Queue = " << q.size() << endl;

    q.split(evenQ, oddQ);

    cout << "\nEven Queue: ";
    evenQ.display();

    cout << "Odd Queue: ";
    oddQ.display();

    return 0;
}
