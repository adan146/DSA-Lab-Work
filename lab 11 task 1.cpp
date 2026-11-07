#include <iostream>
using namespace std;
const int SIZE = 6;
class TokenQueue {
    int arr[SIZE];
    int front, rear, count;
    int nextToken;
public:
    TokenQueue() : front(0), rear(-1), count(0), nextToken(1) {}

    bool isFull()  { return count == SIZE; }
    bool isEmpty() { return count == 0; }

    void issueToken() {
        if (isFull()) {
            cout << "Waiting room is full! Cannot issue more tokens.\n";
            return;
        }
        rear = (rear + 1) % SIZE;
        arr[rear] = nextToken;
        count++;
        cout << "Token " << nextToken << " issued.\n";
        nextToken++;
    }

    void serveCustomer() {
        if (isEmpty()) {
            cout << "Nobody is waiting.\n";
            return;
        }
        cout << "Serving token " << arr[front] << ".\n";
        front = (front + 1) % SIZE;
        count--;
    }

    void showWaiting() {
        if (isEmpty()) {
            cout << "Nobody is waiting.\n";
            return;
        }
        cout << "Waiting tokens: ";
        for (int i = 0, idx = front; i < count; i++, idx = (idx + 1) % SIZE)
            cout << arr[idx] << " ";
        cout << "\n";
    }
};

int main() {
    TokenQueue q;
    int choice;
    do {
        cout << "\n1. Issue token (enqueue)\n2. Serve customer (dequeue)\n"
                "3. Show waiting customers\n4. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: q.issueToken();   break;
            case 2: q.serveCustomer(); break;
            case 3: q.showWaiting();  break;
            case 4: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);
    return 0;
}
