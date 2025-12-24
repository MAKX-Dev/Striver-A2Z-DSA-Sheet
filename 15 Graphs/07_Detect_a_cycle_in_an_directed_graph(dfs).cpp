#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis) {
    pathVis[node] = 1;
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(pathVis[it]) return true;
        if(!vis[it]) {
        if(dfs(it, adj, vis, pathVis) == true) { 
            return true;
        }
    }
    }
    pathVis[node] = 0;
    return false;
}

bool isCycle(int V, vector<vector<int>> &adj) {
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);
    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            if(dfs(i, adj, vis, pathVis) == true) return true;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> adj = {{1,2}, {2}, {}, {0,2}};
    int V = 6;
    if(isCycle) {
        cout << "YES" << endl;
    }
    else {
        cout << "FALSE" << endl;
    }
    return 0;
}