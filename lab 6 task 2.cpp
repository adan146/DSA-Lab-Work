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

    void deleteAtEnd() {
        if (head == NULL) { 
            cout << "List is empty" << endl; 
            return; 
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }

    void deleteAtPosition(int pos) {
        if (head == NULL || pos < 1) { 
            cout << "Invalid position" << endl; 
            return; 
        }
        if (pos == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL) {
            cout << "Invalid position" << endl;
            return;
        }
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }
};

int main() {
    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);

    cout << "Original List: ";
    list.display();

    list.deleteAtEnd();
    cout << "After deleteAtEnd(): ";
    list.display();

    list.deleteAtPosition(2);
    cout << "After deleteAtPosition(2): ";
    list.display();

    return 0;
}