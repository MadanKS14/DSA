#include <iostream>
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
        if (ll.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int topVal = ll.front();
        ll.pop_front();
        return topVal;
    }

    int top()
    {
        if (ll.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
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
    cout << endl;
    return 0;
}