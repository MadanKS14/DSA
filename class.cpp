#include<iostream>
using namespace std;

class Bank {

  string acc_name;
  int acc_num;
  int amount;
  static int total;
  static int total_balance;
  public:
  Bank(string acc_name,int acc_num, int amount){
    this->acc_name=acc_name;
    this->acc_num=acc_num;
    this->amount=amount;
    total++;
    total_balance+=amount;
  }

  static void staticAccess(){
    cout<<total<<endl;
    cout<<total_balance<<endl;
  }


  void Deposit(int amt){
    amount+=amt;
    total_balance+=amt;
  }

  void Disply(){
    cout<<acc_name<<" "<<acc_num<<" "<<amount<<endl;
  }

 
};

int Bank::total=0;
int Bank::total_balance=0;

int main(){
  Bank b1("Madan K S",1, 5000);
  Bank b2("Pavan K S",2 ,7000);
  b1.Disply();
  b2.Disply();
  Bank::staticAccess();
  b1.Deposit(1000);
  b2.Deposit(1000);
  Bank::staticAccess();


  return 0;
}