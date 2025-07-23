#include<iostream>

using namespace std;

void printNum(int n){
    if(n <= 0) return; // base case for n <= 0
    cout << n << " ";
    if(n == 1){
        cout << "\n";
        return;
    }
    printNum(n-1);
}

int main(){
    int num;
    cin >> num; // fixed input
    printNum(num);
}