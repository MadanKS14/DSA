#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;

  Node(int val){
    data=val;
    next=NULL;
  }
};

class List{
  private:
  Node* head;
  Node* tail;

  Node* reverseList(Node* head){
    Node* prev=NULL;
    Node* curr=head;
    Node* next=NULL;

    while(curr!=NULL){
      next=curr->next;
      curr->next=prev;
      prev=curr;
      curr=next;

    }

    return prev;

  }

  public:
  List(){
    head=tail=NULL;
  }

  void push_front(int val){
    Node* newNode = new Node(val);
    if(head== NULL){
      head=tail=newNode;
    }
    else{
      newNode->next=head;
      head=newNode;
    }
  }


  void reverse(){
    tail=head;
    head=reverseList(head);
  }

  void display(){
    Node* temp= head;
    while(temp!=NULL){
      cout<<temp->data<<"->";
      temp=temp->next;
    }
  }
};

int main(){

  List ll;
  ll.push_front(3);
  ll.push_front(2);
  ll.push_front(1);
  ll.display();
  ll.reverse();
  ll.display();
  
  return 0;
}