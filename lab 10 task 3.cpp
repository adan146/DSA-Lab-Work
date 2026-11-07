#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

void push(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) {
        return;
    }
    Node* temp = top;
    cout << temp->data;
    top = top->next;
    delete temp;
}

int main() {
    int num;
    cout << "Enter number: ";
    cin >> num;

    if (num == 0) {
        cout << "Binary: 0" << endl;
    }
    else if (num > 0) {
        while (num > 0) {
            int remainder = num % 2;
            push(remainder);
            num = num / 2;
        }
        cout << "Binary: ";
        while (top != NULL) {
            pop();
        }
        cout << endl;
    }
    else {
        cout << "Enter a non-negative number" << endl;
    }

    return 0;
}