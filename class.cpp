#include<iostream>
using namespace std;

class Area{

  public:
  int calculate(int a){
    return 3.14*a*a;
  }

  int calculate(int a,int b,int c){
    return a*b*c;
  }


};

int main(){


Area a;
cout<<a.calculate(5);
cout<<a.calculate(5,5,5);
return 0;
}