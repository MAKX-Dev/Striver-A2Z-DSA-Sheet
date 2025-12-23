#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int vis[], stack<int> &st, vector<vector<int>> &adj) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it]) dfs(it, vis, st, adj);
    }
    st.push(node);
}

vector<int> topoSort(int V, vector<vector<int>> &adj) {
    int vis[V] = {0};
    stack<int> st;
    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            // dfs function call
            dfs(i, vis, st, adj);
        }
    }
    vector<int> ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main() {
    vector<vector<int>> adj =  {{}, {} , {3}, {1}, {0,1}, {0,2}};
    int V = 6; 
    vector<int> result = topoSort(V, adj);
    cout << "Topo Sort of DAS is: ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}