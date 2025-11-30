#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int> &arr) {
    stack<int> st;
    int n = arr.size();
    vector<int> result(n);
    for(int i = 2*n-1; i >= 0; i++) {
        while(!st.empty() && st.top() <= arr[i % n]) {
            st.pop();
        }
        if(i<n) {
            result[i] = st.empty() ? -1 : st.top();
        }
        st.push(arr[i % n]);
    }
    return result;
}

int main() {
    vector<int> arr = {3, 10, 4, 2, 1, 2, 6, 1, 7, 2, 9};
    vector<int> ans = nextGreaterElements(arr);
    cout << "Next Greater Element array is: ";
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}