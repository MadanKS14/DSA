#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class Queue{
    Node* head;
    Node* tail;

public:
    Queue(){
        head = tail = NULL;
    }

    void push(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop(){
        if(head == NULL){
            cout << "empty queue" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        if(head == NULL) tail = NULL;
    }

    int front(){
        if(head == NULL){
            cout << "empty" << endl;
            return -1;
        }
        return head->data;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    q.display();

    q.pop();
    q.display();

    cout << "Front: " << q.front() << endl;

    return 0;
}