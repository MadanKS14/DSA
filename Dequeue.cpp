#include<iostream>
#include<list>
using namespace std;

int main() {
    list<int> q;

    q.push_back(1);
    q.push_back(2);
    q.push_back(3);

    cout << q.front() << endl; // prints 1

    // To show all elements
    for(int x : q) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}