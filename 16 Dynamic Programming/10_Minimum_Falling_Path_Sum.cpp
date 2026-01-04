#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &matrix,int r, int c, vector<vector<int>> &dp) {
  int n = matrix.size();
  int m = matrix[0].size();
  if(c < 0 || c >= m) {
    return INT_MAX;
  }
  if(r == n - 1) return matrix[r][c];
  if(dp[r][c] != -1) return dp[r][c];
  int down = solve(matrix, r + 1, c, dp);
  int left = solve(matrix, r + 1, c - 1, dp);
  int right = solve(matrix, r + 1, c + 1, dp);
  
  long long result = (long long)matrix[r][c] + min({down, left, right});
  dp[r][c] = (result > INT_MAX) ? INT_MAX : result;
  return dp[r][c];
}

int minFallingPathSum(vector<vector<int>> &matrix) {
  int n = matrix.size();
  int m = matrix[0].size();
  vector<vector<int>> dp(n, vector<int>(m, -1));
  int ans = INT_MAX;
  for(int c = 0; c < m; c++) {
    int val = solve(matrix, 0, c, dp);
    if(val != INT_MAX) {
      ans = min(ans, val);
    }
  }
  return ans;
}

int main() {
  vector<vector<int>> matrix = {{1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};
  int res = minFallingPathSum(matrix);
  cout << " minimum path sum : " << res << endl;
  return 0;
}

