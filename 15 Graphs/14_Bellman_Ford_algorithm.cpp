#include<bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>> &edges, int S) {
  const int INF = 1e9;
  vector<int> dist(V, INF);
  dist[S] = 0;
  for(int i = 0; i < V-1; i++) {
    for(auto it : edges) {
      int u = it[0];
      int v = it[1];
      int wt = it[2];
      if(dist[u] != INF && dist[u] + wt < dist[v]) {
        dist[v] = dist[u] + wt;
      }
    }
  }
  for(auto it : edges) {
    int u = it[0];
    int v = it[1];
    int wt = it[2];
    if(dist[u] != INF && dist[u] + wt < dist[v]) {
      return {-1};
    }
  }
  return dist;
}

int main() {
  int V = 6;
  vector<vector<int>> edges = {{3, 2, 6}, {5, 3, 1}, {0, 1, 5}, {1, 5, -3}, {1, 2, -2}, {3, 4, -2}, {2, 4, 3}};
  int S = 0;
  vector<int> result = bellmanFord(V,edges, S);
  for(int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  } 
  return 0;
}