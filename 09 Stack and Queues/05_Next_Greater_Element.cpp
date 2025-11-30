#include<bits/stdc++.h>
using namespace std;
vector<int> nextLargerElements(vector<int> &arr) {
    int n = arr.size();
    vector<int> result(n);
    stack<int> st;
    for(int i = n-1 ; i >= 0 ; i--) {
        while(!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        if(st.empty()) result[i] = -1;
        else result[i] = st.top();
        st.push(arr[i]);
    }
    return result;
}

int main() {
    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> ans = nextLargerElements(arr);
    cout << "Next Greater Element array is: ";
    for(int i = 0 ; i < ans.size() ; i++) {
        cout << ans[i] << " ";
    }

}