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
    else{
      int topVal=v.back();
      v.pop_back();
      return v.back();
    }
    
  }

  int  top(){
    if(v.empty()){
      cout<<"stack is empty";
      return -1;
    }
    else
    {
      return v.back();
    }
  }

  bool empty(){
    return v.empty();
  }


};

int main(){

  Stack s;
  s.push(10);
  s.push(20);
  s.push(30);

  while(!s.empty()){
    cout<<s.top()<<" ";
    // s.pop();
  }

  s.pop();
  while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
  }

  return 0;
}