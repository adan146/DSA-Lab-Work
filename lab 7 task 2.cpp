#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

int main() {
    // Initial list: 10
    Node* head = new Node{10, NULL, NULL};
    Node* temp = head;
    int arr[] = {200, 300, 400, 500};
    for (int i = 0; i < 4; i++) {
        Node* n = new Node{arr[i], temp, NULL};
        temp->next = n;
        temp = n;
    }
    // List now: 10 -> 200 -> 300 -> 400 -> 500

    // Insert 100 at start
    Node* n = new Node{100, NULL, head};
    head->prev = n;
    head = n;
    // List: 100 -> 10 -> 200 -> 300 -> 400 -> 500

    // Insert 350 after 300
    temp = head;
    while (temp->data != 300) temp = temp->next;
    n = new Node{350, temp, temp->next};
    temp->next->prev = n;
    temp->next = n;
    // List: 100 -> 10 -> 200 -> 300 -> 350 -> 400 -> 500

    // Insert 600 at end
    temp = head;
    while (temp->next != NULL) temp = temp->next;
    n = new Node{600, temp, NULL};
    temp->next = n;
    // List: 100 -> 10 -> 200 -> 300 -> 350 -> 400 -> 500 -> 600

    // Delete from start
    temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
    // List: 10 -> 200 -> 300 -> 350 -> 400 -> 500 -> 600

    // Delete 400 (middle)
    temp = head;
    while (temp->data != 400) temp = temp->next;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    // List: 10 -> 200 -> 300 -> 350 -> 500 -> 600

    // Delete from end
    temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->prev->next = NULL;
    delete temp;
    // Final List: 10 -> 200 -> 300 -> 350 -> 500

    // Display
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}