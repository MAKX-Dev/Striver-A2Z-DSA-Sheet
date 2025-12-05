#include<bits/stdc++.h>
using namespace std;

class MinStack {
    stack<int> st;
    int mini = INT_MAX;
    public:
    void push(int val) {
        if(st.empty()) {
            mini = val;
            st.push(val);
        }
        else {
            if(val > mini) st.push(val);
            else st.push(2 * val - mini);
        }
        mini = val;
    }
    void pop() {
        if(st.empty()) return;
        int x = st.top();
        st.pop();
        if(x < mini) mini = 2 * mini - x;
    } 
    int top() {
        if(st.empty()) return;
        int x = st.top();
        if(mini < x) return x;
        return mini;
    }
    int getMin() {
        return mini;
    }
};

int main() {

}