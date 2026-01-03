#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &matrix, int r, int c, vector<vector<int>> &dp) {
  int m = matrix.size();
  int n = matrix[0].size();
  if(r >= m || c >= n) return 0;
  if(dp[r][c] != -1) {
    return dp[r][c];
  }
  if(matrix[r][c] == 1) return 0;
  if(r == m - 1 && c == n-1) {
    return 1;
  } 
  dp[r][c] = solve(matrix, r + 1, c, dp) + solve(matrix, r, c + 1, dp);
  return dp[r][c];
}

int uniquePath(vector<vector<int>> &matrix) {
  int m = matrix.size();
  int n = matrix[0].size();
  vector<vector<int>> dp(m, vector<int>(n, -1));
  int res = solve(matrix, 0, 0, dp);
  return res;
}

int main() {
  vector<vector<int>> matrix = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  int ans = uniquePath(matrix);
  cout << ans << endl;
  return 0;
}