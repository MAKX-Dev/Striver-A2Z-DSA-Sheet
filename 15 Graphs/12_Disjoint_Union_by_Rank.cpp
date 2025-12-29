#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
  vector<int> rank, parent;
  public:
  DisjointSet(int n ) {
    rank.resize(n+1, 0);
    parent.resize(n+1);
    for(int i = 0; i <= n; i++) {
      parent[i] = i;
    }
  }

findUparent(int node) {
  if(node == parent[node]) return node;
  return parent[node] = findUparent(parent[node]);
}

void UnionByRank(int u, int v) {
  int ulp_u = findUparent(u);
  int ulp_v = findUparent(v);
  if(ulp_v == ulp_u) return;
  if(rank[ulp_u] < rank[ulp_v]) {
    parent[ulp_u] = ulp_v;
  }
  else if(rank[ulp_v] < rank[ulp_u]) {
    parent[ulp_v] = ulp_u;
  }
  else {
    parent[ulp_v] = ulp_u;
    rank[ulp_u]++;
  }
}
};

int main() {
  DisjointSet ds(7);
  ds.UnionByRank(1, 2);
  ds.UnionByRank(2, 3);
  ds.UnionByRank(4, 5);
  ds.UnionByRank(6, 7);
  if(ds.findUparent(3) == ds.findUparent(7)) {
    cout << "same" << endl;
  }
  else {
    cout << "not same" << endl;
  }
  ds.UnionByRank(3, 7);
  return 0;
}