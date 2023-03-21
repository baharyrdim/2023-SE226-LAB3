#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
    int count;
public:
    Queue() {
        front = NULL;
        rear = NULL;
        count = 0;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(int item) {
        Node* newNode = new Node;
        newNode->data = item;
        newNode->next = NULL;
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        count--;
    }

    int top() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return (count == 0);
    }

    int size() {
        return count;
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Size of queue: " << q.size() << endl;
    cout << "Top element of queue: " << q.top() << endl;
    q.dequeue();
    cout << "Top element of queue after dequeue: " << q.top() << endl;
    q.dequeue();
    q.dequeue();
    cout << "Is queue empty? " << q.isEmpty() << endl;
    return 0;
}
