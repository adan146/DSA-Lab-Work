#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(NULL) {}
};

class LinkedList {
    Node* head;
public:
    LinkedList() : head(NULL) {}

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) { 
            head = newNode; 
            return; 
        }
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

    void deleteByValue(int value) {
        if (head == NULL) { 
            cout << "List is empty" << endl; 
            return; 
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* curr = head;
        while (curr->next != NULL && curr->next->data != value) {
            curr = curr->next;
        }

        if (curr->next != NULL) {
            Node* toDelete = curr->next;
            curr->next = toDelete->next;
            delete toDelete;
        } else {
            cout << "Value not found" << endl;
        }
    }
};

int main() {
    LinkedList list;
    for (int v = 10; v <= 50; v += 10)
        list.insertAtEnd(v);

    cout << "Original: ";
    list.display();

    cout << "Delete 10 (first): ";
    list.deleteByValue(10);
    list.display();

    cout << "Delete 30 (middle): ";
    list.deleteByValue(30);
    list.display();

    cout << "Delete 50 (end): ";
    list.deleteByValue(50);
    list.display();

    cout << "Delete 99 (not found): ";
    list.deleteByValue(99);

    return 0;
}