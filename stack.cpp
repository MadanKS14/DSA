
// stack using vectors

#include<iostream>
#include<vector>
using namespace std;

class Stack{
  public:
  vector<int> v;

  void push(int val){
    v.push_back(val);
  }

  int pop(){
    if(v.empty()){
      cout<<"stack is empty";
      return -1;
    }
    int topVal=v.back();
    v.pop_back();
    return topVal;
  }

  int top(){
    if(v.empty()){
      cout<<"stack is empty";
      return -1;
    }

    return v.back();
  }

  bool empty(){
    return v.empty();
  }

};


int main(){
  Stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  s.push(6);

  cout<<s.pop()<<endl;
  cout<<s.top()<<endl;
  cout<<s.empty();

  return 0;
}