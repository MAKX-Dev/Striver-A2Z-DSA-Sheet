#include<bits/stdc++.h>
using namespace std;
class stImpl {
    int top = -1;
    int st[10];
    public:
    void push(int x) {
        if(top >= 9) {
            cout << "Stack Overflow" << endl;
            return;
        }
        top = top + 1;
        st[top] = x;
    }
    int topU() {
    if(top == -1) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return st[top];
}
void popU() {
    if(top == -1) {
        cout << "Stack Underflow" << endl;
        return ;
    }
    top = top - 1;
}
int size() {
    return top + 1;
}
};

int main() {
    stImpl s;
    s.push(10);
    s.push(20);
    cout << "Top element: " << s.topU() << endl;
    cout << "Size: " << s.size() << endl;
    s.popU();
    cout << "Top element after pop: " << s.topU() << endl;
    return 0;
}

