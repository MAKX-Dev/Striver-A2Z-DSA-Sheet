#include<bits/stdc++.h>
using namespace std;

bool isCycle(int V, vector<vector<int>> &adj) {
    vector<int> vis(V, 0);
    vector<int> parent(V, -1);
    queue<int> q;
    for(int i = 0; i < V; i++) {
        if(! vis[i]) {
            q.push(i);
            vis[i] = 1;
            parent[i] = -1;
            while(! q.empty()) {
                int node = q.front();
                q.pop();
                for(auto it : adj[node]) {
                    if(! vis[it]) {
                        vis[it] = 1;
                        parent[it] = node;
                        q.push(it);
                    }
                    else if(it != parent[node]) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    vector<vector<int>> adj = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
    int V = 6;
    bool result = isCycle(V, adj);
    if(result) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return true;
}