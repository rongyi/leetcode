// https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/
#include "xxx.hpp"

class Solution {
public:
  int numberOfPaths(vector<vector<int>> &grid, int k) {
    m_ = grid.size();
    n_ = grid[0].size();

    return dfs(grid, k, 0, 0, 0);
  }

private:
  int dfs(vector<vector<int>> &grid, int k, int i, int j, int cur) {
    if (i >= m_ || j >= n_) {
      return 0;
    }
    if (i == m_ - 1 && j == n_ - 1) {
      return (cur + grid[i][j]) % k ? 0 : 1;
    }
    if (dp_[i * n_ + j][cur] == 0) {
      dp_[i * n_ + j][cur] =
          (1 + dfs(grid, k, i + 1, j, (cur + grid[i][j]) % k) +
           dfs(grid, k, i, j + 1, (cur + grid[i][j]) % k)) %
          int(1e9 + 7);
    }
    return dp_[i * n_ + j][cur] - 1;
  }

private:
  int m_;
  int n_;
  int dp_[50001][51] = {};
};
