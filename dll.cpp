#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList {
    Node* head;
    Node* tail;

public:
    DoublyList() {
        head = tail = NULL;
    }

    // Insert at front
    void push_front(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at back
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
        // newNode->prev = tail;
        // tail->next = newNode;
        // tail = newNode;
    }

    // Remove first element
    void pop_front() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        if (head == tail) { 
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }

    // Remove last element
    void pop_back() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        if (head == tail) { 
            delete head;
            head = tail = NULL; 
            return;
        }
        Node* temp = tail;
        tail = temp->prev;
        tail->next = NULL;
        delete temp;
    }

    // Display list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyList ll;
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.display();

    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(7);
    ll.display();

    ll.pop_front();
    ll.pop_front();
    ll.display();

    ll.pop_back();
    ll.pop_back();
    ll.display();

    return 0;
}
