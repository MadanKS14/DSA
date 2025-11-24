#include<iostream>
using namespace std;

class CQ {
    int *arr;
    int cap, currsize, front, rear;
public:
    CQ(int n) {
        cap = n;
        arr = new int[cap];
        currsize = 0;
        front = 0;
        rear = -1;
    }

    void push(int val) {
        if (currsize == cap) {
            cout << "Queue is full" << endl;
            return;
        }
        rear = (rear + 1) % cap;
        arr[rear] = val;
        currsize++;
    }

    void pop() {
        if (currsize == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        front = (front + 1) % cap;
        currsize--;
    }

    int Front() {
        if (currsize == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

};

int main() {
    CQ q(3);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << q.Front() << endl;

    q.pop();
    cout << q.Front() << endl;

    q.pop();
    q.pop();
    q.pop();

    return 0;
}