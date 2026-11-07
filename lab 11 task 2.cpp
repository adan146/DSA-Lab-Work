#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

class LinkedQueue {
    Node* front;
    Node* rear;
public:
    LinkedQueue() : front(nullptr), rear(nullptr) {}
    ~LinkedQueue() { clearQueue(); }

    void enqueue(int v) {
        Node* n = new Node(v);
        if (rear == nullptr) front = rear = n;
        else { rear->next = n; rear = n; }
    }

    void dequeue() {
        if (front == nullptr) { cout << "Queue is empty.\n"; return; }
        Node* t = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        cout << "Dequeued: " << t->data << "\n";
        delete t;
    }

    void display() {
        if (front == nullptr) { cout << "Queue is empty.\n"; return; }
        for (Node* p = front; p; p = p->next) cout << p->data << " ";
        cout << "\n";
    }

    int countNodes() {
        int c = 0;
        for (Node* p = front; p; p = p->next) c++;
        return c;
    }
    void displayRear() {
        if (rear == nullptr) cout << "Queue is empty.\n";
        else cout << "Rear value: " << rear->data << "\n";
    }

    void clearQueue() {
        while (front != nullptr) {
            Node* t = front;
            front = front->next;
            delete t;
        }
        rear = nullptr;
    }
};

int main() {
    LinkedQueue q;
    int vals[5] = {10, 20, 30, 40, 50};
    for (int v : vals) q.enqueue(v);

    cout << "Queue: ";            q.display();
    cout << "Count: " << q.countNodes() << "\n";
    q.displayRear();

    q.dequeue();
    cout << "After dequeue: ";    q.display();
    cout << "Count: " << q.countNodes() << "\n";
    q.displayRear();

    q.clearQueue();
    cout << "After clearQueue: "; q.display();
    cout << "Count: " << q.countNodes() << "\n";
    q.displayRear();
    return 0;
}
