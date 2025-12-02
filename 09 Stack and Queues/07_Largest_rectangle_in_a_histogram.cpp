#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights) {
    stack<int> st;
    int maxArea = 0;
    int NSE = -1;
    int PSE = -1;
    int element = 0;
    for(int i = 0; i < heights.size(); i++) {
        while(! st.empty() && heights[st.top()] > heights[i]) {
            element  = st.top();
            st.pop();
            NSE = i;
            PSE = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, heights[element] * (NSE - PSE - 1));
        }
        st.push(i);
    }
    while(! st.empty()) {
        NSE = heights.size();
        element = st.top();
        PSE = st.empty() ? -1 : st.top();
        st.pop();
        maxArea = max(maxArea, (NSE - PSE - 1) * element);
    }
    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int result = largestRectangleArea(heights);
    cout << "area of the largest rectangle in the histogram is: " << result << endl;
    return 0;
}