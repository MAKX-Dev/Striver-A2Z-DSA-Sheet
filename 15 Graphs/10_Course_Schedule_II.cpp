#include<bits/stdc++.h>
using namespace std;

vector<int> canFinish(int N, vector<vector<int>> &arr) {
      vector<vector<int>> adj(N);
      vector<int> inDegree(N, 0);
      for (auto &it : arr) {
        int u = it[1]; 
        int v = it[0]; 
        adj[u].push_back(v);
        inDegree[v]++;
    }
    queue<int> q;
    for(int i = 0; i < N; i++) {
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
    if(topo.size() == N) return topo;
    return {};
    }

int main() {
  vector<vector<int>> arr = {{1,0}};
  int N = 2;
  vector<int> result = canFinish(N, arr);
  for(int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  return 0;
}