#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* top = NULL;

void push(string page) {
    Node* newNode = new Node;
    newNode->data = page;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL || top->next == NULL) {
        cout << "Cannot go back" << endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
    cout << "Current page: " << top->data << endl;
}

void peek() {
    if (top == NULL) {
        cout << "No page visited" << endl;
    }
    else {
        cout << "Current page: " << top->data << endl;
    }
}

void display() {
    if (top == NULL) {
        cout << "History is empty" << endl;
        return;
    }
    Node* temp = top;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main() {
    int choice;
    string page;
    do {
        cout << "\n1. Visit Page" << endl;
        cout << "2. Back" << endl;
        cout << "3. Current Page" << endl;
        cout << "4. History" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter page: ";
                cin >> page;
                push(page);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 0:
                break;
        }
    } while (choice != 0);

    return 0;
}