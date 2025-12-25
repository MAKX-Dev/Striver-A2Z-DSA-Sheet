#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<vector<int>> &adj) {
    int inDegree[V] = {0};
    for(int i = 0; i < V; i++) {
        for(auto it : adj[i]) {
            inDegree[it]++;
        }
    }
    queue<int> q;
    for(int i = 0; i < V; i++) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it : adj[node]) {
            inDegree[it]--;
            if(inDegree[it] == 0) q.push(it);
        }
    }
    return topo;
}

int main() {
    vector<vector<int>> adj = {{} , {0}, {0}, {0}};
    int V = 4;
    vector<int> result = topoSort(V, adj);
    cout << " Topological Sorting is: ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}