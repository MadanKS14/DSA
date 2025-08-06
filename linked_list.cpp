#include <iostream>
using namespace std;

// Node structure for singly linked list
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Linked List class
class List {
private:
    Node* head;
    Node* tail;

public:
    // Constructor to initialize empty list
    List() {
        head = tail = nullptr;
    }

    // Insert at the front of the list
    void push_front(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // Insert at the end of the list
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Remove the first element
    void pop_front() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;

        if (!head) tail = nullptr; // List became empty
    }

    // Remove the last element
    void pop_back() {
        if (!head) return;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }

        delete tail;
        tail = temp;
        tail->next = nullptr;
    }

    // Insert at a specific position (0-based index)
    void insert(int val, int pos) {
        if (pos < 0) {
            cout << "Invalid position!" << endl;
            return;
        }

        if (pos == 0) {
            push_front(val);
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            if (!temp) {
                cout << "Invalid position!" << endl;
                return;
            }
            temp = temp->next;
        }

        if (!temp) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        if (newNode->next == nullptr) {
            tail = newNode; // If inserted at the end, update tail
        }
    }

    // Search for a value and return its index (0-based), or -1 if not found
    int search(int key) {
        Node* temp = head;
        int idx = 0;
        while (temp) {
            if (temp->data == key)
                return idx;
            temp = temp->next;
            idx++;
        }
        return -1; // Not found
    }

    // Display the linked list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Driver code
int main() {
    List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);        // List: 3 -> 2 -> 1
    ll.insert(4, 1);         // List: 3 -> 4 -> 2 -> 1
    ll.display();

    ll.insert(7, 2);         // List: 3 -> 4 -> 7 -> 2 -> 1
    ll.display();

    cout << "Search 5: " << ll.search(5) << endl; // Not found → -1
    cout << "Search 4: " << ll.search(4) << endl; // Found at index 1

    ll.pop_front();          // Remove 3
    ll.pop_back();           // Remove 1
    ll.display();            // List: 4 -> 7 -> 2

    return 0;
}
