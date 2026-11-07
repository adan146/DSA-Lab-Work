#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtStart(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

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
    while (temp != nullptr && temp->data != afterValue) temp = temp->next;
    if (temp == nullptr) return false;
    Node* newNode = new Node;
    newNode->data = newValue;
    newNode->next = temp->next;
    temp->next = newNode;
    return true;
}

void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

void freeList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;
    int choice, value, afterValue;

    do {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1) Insert at Start\n";
        cout << "2) Insert at End\n";
        cout << "3) Insert in Middle\n";
        cout << "4) Display List\n";
        cout << "5) Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtStart(head, value);
                cout << "Inserted at start.\n";
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(head, value);
                cout << "Inserted at end.\n";
                break;

            case 3:
                cout << "Enter value after which you want to insert: ";
                cin >> afterValue;
                cout << "Enter new value: ";
                cin >> value;
                if (insertAfter(head, afterValue, value))
                    cout << "Inserted after " << afterValue << ".\n";
                else
                    cout << afterValue << " not found in the list.\n";
                break;

            case 4:
                cout << "Current List: ";
                display(head);
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    freeList(head);
    return 0;
}