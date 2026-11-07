#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* top = NULL;

void push(string word) {
    Node* newNode = new Node;
    newNode->data = word;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) {
        cout << "Nothing to undo" << endl;
        return;
    }
    Node* temp = top;
    cout << "Undone: " << top->data << endl;
    top = top->next;
    delete temp;
}

void peek() {
    if (top == NULL) {
        cout << "Editor is empty" << endl;
    }
    else {
        cout << "Last word: " << top->data << endl;
    }
}

int size() {
    int count = 0;
    Node* temp = top;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    push("Hello");
    push("World");
    cout << "Word count: " << size() << endl;

    pop();
    cout << "Word count: " << size() << endl;
    peek();

    return 0;
}