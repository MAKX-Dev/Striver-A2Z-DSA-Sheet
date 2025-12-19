#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &list) {
    vis[node] = 1;
    list.push_back(node);
    for(auto it : adj[node]) {
        if(!vis[it]) {
           dfs(it, adj, vis, list);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<vector<int>> &adj) {
    vector<int> vis(V, 0);
    int start = 0;
    vector<int> list;
    dfs(start, adj, vis, list);
    return list;
}


int main() {
    vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    int V = 5;
    vector<int> result = dfsOfGraph(V, adj);
    cout << "DFS Transversal of Graph is: ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}