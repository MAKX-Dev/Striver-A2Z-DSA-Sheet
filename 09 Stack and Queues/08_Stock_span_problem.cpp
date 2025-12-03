#include<bits/stdc++.h>
using namespace std;
vector<int> stockSpan(vector<int> &arr, int n) {
    stack<int> st;
    vector<int> span(n);
    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }
        if(st.empty()) {
            span[i] = i + 1;
        }
        else {
            span[i] = i - st.top();
        }
        st.push(i);
    }
    return span;
}

int main() {
    vector<int> arr = {120, 100, 60, 80, 90, 110, 115};
    int n = arr.size();
    vector<int> result = stockSpan(arr, n);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}