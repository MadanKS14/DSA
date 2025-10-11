#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
 
  Node(int val)
  {
    data = val;
    next =NULL;
  }
};

class Queue
{
  Node *head;
  Node *tail;

public:
  Queue()
  {
    head = tail = NULL;
  }

  void push(int val)
  {
    Node *newnode = new Node(val);
    if (head == NULL)
    {
      head = tail = newnode;
      return ;
    }
    else
    {
      tail->next=newnode;
      tail=newnode;
    }
  }

  void pop(){
    if(head==NULL){
      cout<<"list is empty";
      return;
    }
    if(head==tail){
      delete head;
      head=tail=NULL;
    }
    Node* temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;
  }

  int front(){
        if(head == NULL){
            cout << "empty" << endl;
            return -1;
        }
        return head->data;
    }

  void show(){
    Node* temp=head;
    while(temp!=NULL){
      cout<<temp->data<<"=";
      temp=temp->next;
    }
    cout<<"NULL";
  }
};

  int main(){

    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q.pop();
    q.pop();

    q.show();

    cout<<q.front();

    return 0;
  }