#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &parent) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(vis[it] == 0) {
                parent[it] = node;
                if (dfs(it, adj, vis, parent)) return true;
            }
                else if(vis[it] == 1 && it != parent[node]) {
                    return true;
            }
        }
            return false;
        }

bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> parent(V, -1);
        int start = 0;
        for(int i = 0; i < V; i++) {
            if(vis[i] == 0) {
                if(dfs(i, adj, vis,parent)) return true;
            }
        }
        return false;
    }

int main() {
    vector<int> adj[] = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
    int V = 6;
    bool result = isCycle(V, adj);
    if(isCycle) {
        cout << "YES" << endl;
    }
    else {
        cout << "FALSE" << endl;
    }
    return true;
}