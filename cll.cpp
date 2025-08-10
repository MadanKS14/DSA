#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularList {
    Node* head;
    Node* tail;

public:
    CircularList() {
        head = tail = NULL;
    }

    void insert_head(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
            tail->next = head;
            return;
        }
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }

    void insert_tail(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
            tail->next = head;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }

    void rm_head() {
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
        delete temp;
        tail->next = head;
    }

    void rm_tail() {
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
        while (temp->next != tail) { 
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = head;
    }

    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";
    }
};

int main() {
    CircularList cl;

    cl.insert_head(1);
    cl.insert_head(2);
    cl.insert_head(3);
    cl.display();

    cl.insert_tail(0);
    cl.insert_tail(-1);
    cl.display();

    cl.rm_head();
    cl.display();

    cl.rm_tail();
    cl.display();

    return 0;
}
