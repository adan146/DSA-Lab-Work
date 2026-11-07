#include <iostream>
using namespace std;
const int SIZE = 4;
class CircularQueue {
    int arr[SIZE];
    int front, rear, count;
public:
    CircularQueue() : front(0), rear(-1), count(0) {}
  void enqueue(int v) {
        if (count == SIZE) { cout << "enqueue(" << v << "): queue FULL\n"; return; }
        rear = (rear + 1) % SIZE;
        arr[rear] = v;
        count++;
    }
    void dequeue() {
        if (count == 0) { cout << "dequeue(): queue EMPTY\n"; return; }
        front = (front + 1) % SIZE;
        count--;
    }
    void print(int step, const string& op) {
        cout << step << "\t" << op << "\t" << front << "\t" << rear << "\t" << count << "\n";
    }
};
int main() {
    CircularQueue q;
    cout << "Step\tOperation\tfront\trear\tcount\n";
    int ops[] = {101,102,103,104,105,-1,-1,105,106};
    for (int i = 0; i < 9; i++) {
        string name;
        if (ops[i] == -1) { q.dequeue(); name = "dequeue()"; }
        else { q.enqueue(ops[i]); name = "enqueue(" + to_string(ops[i]) + ")"; }
        q.print(i + 1, name);
    }
    return 0;
}
