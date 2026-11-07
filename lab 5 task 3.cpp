#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    if (head == nullptr) { 
        head = newNode; 
        return; 
    }
    Node* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = newNode;
}

bool insertAfter(Node* head, int afterValue, int newValue) {
    Node* temp = head;
    while (temp != nullptr && temp->data != afterValue) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        return false;
    }
    Node* newNode = new Node;
    newNode->data = newValue;
    newNode->next = temp->next;
    temp->next = newNode;
    return true;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int n, value, afterValue, newValue;

    cout << "Enter number of values: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(head, value);
    }

    cout << "Original Linked List: ";
    display(head);

    cout << "Enter value after which you want to insert: ";
    cin >> afterValue;
    cout << "Enter new value: ";
    cin >> newValue;

    if (insertAfter(head, afterValue, newValue)) {
        cout << "Linked List after insertion: ";
        display(head);
    } else {
        cout << afterValue << " not found in the list. List unchanged: ";
        display(head);
    }

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}