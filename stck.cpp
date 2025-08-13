#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Stack
{
public:
  list<int> ll;

  void push(int val)
  {
    ll.push_front(val);
  }

  int pop()
  {
    if(ll.empty()){
      cout<<"stack is empty";
    }
    
    ll.pop_front();
  }

  int top()
  {
    return ll.front();
  }

  bool empty()
  {
    return ll.empty();
  }
};

int main()
{

  Stack s;
  s.push(10);
  s.push(20);
  s.push(30);

  while (!s.empty())
  {
    cout << s.top() << " ";
    s.pop();
  }

  return 0;
}