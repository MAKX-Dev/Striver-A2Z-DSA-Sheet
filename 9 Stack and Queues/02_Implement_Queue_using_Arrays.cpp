#include<bits/stdc++.h>
using namespace std;
class qImpl {
    int front = -1;
    int rear = -1;
    int q[10];
    public:
    void push(int x) {
        if(rear >= 9) {
            cout << "Queue Overflow" << endl;
            return;
        }
        if(front == -1) {
            front = 0;
        }
        rear = rear +1;
        q[rear] = x;
    }
    public:
    int frontU() {
    if(front == -1) {
        cout << "Queue is Empty" << endl;
        return -1;
    }
    return q[front];
}
public:
void popU() {
    if(front == -1 || front > rear) {
        cout << "Queue Underflow" << endl;
        return;
    } 
    front = front + 1;;
    if(front > rear) {
        front = -1;
        rear = -1;
    }
}
int size() {
    if(front == -1) return 0;
    return rear - front + 1;
}
};

int main() {
    qImpl q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "Front element: " << q.frontU() << endl;
    cout << "Size: " << q.size() << endl;
    q.popU();
    cout << "Front element after pop: " << q.frontU() << endl;
    cout << "Size after pop: " << q.size() << endl;
    return 0;
}