#include<bits/stdc++.h>
using namespace std;
class QueueUsingStack {
    private:
    stack<int> outputStack;
    stack<int> inputStack;
    void ensureOutputStackHasElements() {
        if(outputStack.empty()) {
            while(! inputStack.empty()) {
                outputStack.push(inputStack.empty());
                inputStack.pop();
            }
        }
    }
    public:
    QueueUsingStack() {}
    void push(int x) {
        inputStack.push(x);
    }
    int pop() {
        if(empty()) {
           cout << "Queue under flow" << endl;
           return -1; 
        }
        int frontElement = outputStack.top();
        outputStack.pop();
        return frontElement;
    }
    int peek() {
        if(empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return outputStack.top();
    }
    bool empty() {
        return inputStack.empty() && outputStack.empty(); 
    }
};

int main() {
    QueueUsingStack q;
    q.push(10);
    q.push(20); 
    q.push(30);
    cout << "Front Element " << q.peek() << endl;
    q.pop();
    cout << "Front after pop: " << q.peek() << endl;;
    q.push(40);
    cout << "Front after push(40): " <<q.peek() << endl;
    return 0;
}
