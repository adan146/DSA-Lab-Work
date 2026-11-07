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

    void deleteAtStart() {
        if (head == NULL) { 
            cout << "List is empty" << endl; 
            return; 
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
};

int main() {
    LinkedList list;
    for (int v = 10; v <= 50; v += 10)
        list.insertAtEnd(v);

    cout << "Original: ";
    list.display();

    list.deleteAtStart();
    cout << "After 1st delete: ";
    list.display();

    list.deleteAtStart();
    cout << "After 2nd delete: ";
    list.display();

    return 0;
}