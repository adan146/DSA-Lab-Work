#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;

void addStart(int value) {
    Node* n = new Node;
    n->data = value;
    n->prev = nullptr;
    n->next = head;
    if (head != nullptr)
        head->prev = n;
    head = n;
}

void addEnd(int value) {
    Node* n = new Node;
    n->data = value;
    n->next = nullptr;
    if (head == nullptr) {
        n->prev = nullptr;
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = n;
    n->prev = temp;
}

void insertAfter(int target, int value) {
    Node* temp = head;
    while (temp != nullptr && temp->data != target)
        temp = temp->next;

    if (temp == nullptr)
        return;

    Node* n = new Node;
    n->data = value;
    n->prev = temp;
    n->next = temp->next;

    if (temp->next != nullptr)
        temp->next->prev = n;

    temp->next = n;
}

void display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    addEnd(40);
    addEnd(50);
    addEnd(60);
    addEnd(70);
    addEnd(80);
    addEnd(90); // tumhari output me 90 hai is liye add kiya
    addStart(30);
    insertAfter(30, 35);

    cout << "Final List: ";
    display();
    return 0;
}