#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int V, vector<vector<int>> &adj) {
  vector<int> depth(V, -1);
  queue<int> q;
  depth[0] = 0;
  q.push(0);
  while(!q.empty()) {
    int u = q.front(); 
    q.pop();
    for(auto it : adj[u]) {
      if(depth[it] == -1) {
        depth[it] = depth[u] + 1;
        q.push(it);
      }
    }
  }
  return depth;
}

int main() {
  vector<vector<int>> adj = {{1,3}, {0,2,3}, {1,6}, {0,4}, {3,5}, {4,6}, {2,5,7,8}, {6,8}, {6,7}};
  int V = 9;
  cout << "Shortest path list is: ";
  vector<int> result = shortestPath(V, adj);
  for(int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  return 0;
}