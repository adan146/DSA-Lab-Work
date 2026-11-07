#include <iostream>
#include <stack>
using namespace std;
const int SIZE = 100;
class ArrayQueue {
public:
    int arr[SIZE];
    int front = 0, rear = -1, count = 0;

    void enqueue(int v) {
        if (count == SIZE) { cout << "Queue full\n"; return; }
        rear = (rear + 1) % SIZE;
        arr[rear] = v;
        count++;
    }
    int dequeue() {
        int v = arr[front];
        front = (front + 1) % SIZE;
        count--;
        return v;
    }
    bool isEmpty() { return count == 0; }
    void display() {
        for (int i = 0, idx = front; i < count; i++, idx = (idx + 1) % SIZE)
            cout << arr[idx] << " ";
        cout << "\n";
    }
};

void reverseQueue(ArrayQueue& q) {
    stack<int> s;
    while (!q.isEmpty()) s.push(q.dequeue());   
    while (!s.empty()) { q.enqueue(s.top()); s.pop(); } 
}
int main() {
    ArrayQueue q;
    for (int v : {10, 20, 30, 40}) q.enqueue(v);
    cout << "Before: "; q.display();
    reverseQueue(q);
    cout << "After:  "; q.display();
    return 0;
}
