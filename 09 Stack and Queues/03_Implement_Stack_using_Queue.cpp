#include<bits/stdc++.h>
using namespace std;
class StackUisngQueue {
    private:
    queue<int> q1;
    queue<int> q2;
    public:
    int StackUsingQueue() {}
    void push(int x) {
        q2.push(x);
        while(!q1.empty()) {
            q1.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    int pop() {
        if(q1.empty()) {
            cout << "stack Underflow" << endl;
            return -1;
        }
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }
    int top() {
        if(q1.empty()) {
            cout << "Stack is empty "  << endl;
            return -1;
        }
        return q1.front();
    }
    bool empty() {
        return q1.empty();
    }
    int size() {
        return q1.size();
    }
};

int main() {
    StackUisngQueue s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Current Top: " << s.top() << endl;
    cout << "Stack size: " << s.size() << endl;
    s.pop();
    cout << "Current Top: " << s.top() << endl;
    s.pop();
    s.pop();
    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;
    return 0;
}