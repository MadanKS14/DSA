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
  Node* head;
  Node* tail;

  public:
  List(){
    head = tail = NULL;
  }

  void push_front(int val){
    Node* newNode = new Node(val);
    if(head == NULL){
      head=tail=newNode;
      return;
    }
    else{
      newNode->next = head;
      head = newNode;
    }
  }

  void push_back(int val){
    Node* newNode = new Node(val);

    if(head == NULL){
      head= tail= newNode;
      return;
    }else{
      tail->next = newNode;
      tail=newNode;
    }
  }

  void pop_front(){
    if(head == NULL){
      return;
    }
    else{
      Node* temp=head;
      head=head->next;
      temp->next=NULL;
      delete temp;
    }
  }


  void pop_back(){
    if(head == NULL){
      return;
    }
    else{
      Node* temp=head;
      while(temp->next->next!=NULL){
        temp=temp->next;
      }
      temp->next=NULL;

      delete tail;
      tail=temp;

    }

  }

  void insert(int val,int pos){
    if(pos<0){
      cout<<"invalid position "<<endl;
      return;
    }

    if(pos == 0){
      push_back(val);
      return;
    }

    Node* temp = head;
    for(int i=0;i<pos-1;i++){
      if(temp==NULL){
        cout<<"invalid position ";
      }
      temp=temp->next;
    }
    Node* newNode = new Node(val);
    newNode->next=temp->next;
    temp->next=newNode;
  }

  int search(int key){
    Node* temp=head;
    int idx=0;
    while(temp != NULL){
      if(temp->data == key){
        return idx;
      }
      temp=temp->next;
      idx++;
    }
  return -1;
  }

  void display(){
  Node* temp = head;
  while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->next;
  }
  cout<<endl;
}

};



int main(){

  List ll;
  ll.push_front(1);
  ll.push_front(2);
  ll.push_front(3);
  ll.insert(4,1);
  ll.display();

  ll.insert(7,2);
  ll.display();
  cout<<ll.search(5);


  return 0;
}