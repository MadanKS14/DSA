#include <iostream>

using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *prev;

  Node(int val)
  {
    data = val;
    next = prev = NULL;
  }
};

class DoublyList
{
  Node *head;
  Node *tail;

public:
  DoublyList()
  {
    head = tail = NULL;
  }

  void push_front(int val)
  {
    Node *newNode = new Node(val);
    if (head == NULL)
    {
      head = tail = newNode;
    }
    else
    {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
  }

  void push_back(int val)
  {
    Node *newNode = new Node(val);
    if (head == NULL)
    {
      head = tail = newNode;
      return;
    }

    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
  }

  void pop_front()
  {

    if (head == NULL)
    {
      cout << "no list";
      return;
    }

    if (head == tail)
    {
      delete head;
      head = tail = NULL;
      return;
    }

    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
  }

  void pop_back()
  {
    if (head == NULL)
    {
      cout << "no list";
      return;
    }

    if (head == tail)
    {
      delete head;
      return;
    }
    Node *temp = tail;
    tail = temp->prev;
    tail->next = NULL;
    delete temp;
  }

  void display()
  {
    Node *temp = head;
    while (temp != NULL)
    {
      cout << temp->data << " <=> ";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
};

int main()
{
  DoublyList ll;
  ll.push_front(4);
  ll.push_front(3);
  ll.push_front(2);
  ll.push_front(1);

  ll.display();

  ll.push_back(5);
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