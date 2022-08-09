// https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/
#include "xxx.hpp"

class Solution {
public:
  // dfs + memo
  int countPaths(vector<vector<int>> &grid) {
    long long ret = 0;
    long long mod = 1e9 + 7;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        ret = (ret + dfs(grid, i, j, 0)) % mod;
      }
    }

    return ret;
  }

private:
  int dfs(vector<vector<int>> &grid, int i, int j, int prev) {
    // not valid next path
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
      return 0;
    }
    // not strictly increasing
    if (grid[i][j] <= prev) {
      return 0;
    }
    // attch to those value, this is how we cache
    if (dp_[i][j]) {
      return dp_[i][j];
    }
    dp_[i][j] =
        (1LL + dfs(grid, i + 1, j, grid[i][j]) +
         dfs(grid, i - 1, j, grid[i][j]) + dfs(grid, i, j + 1, grid[i][j]) +
         dfs(grid, i, j - 1, grid[i][j])) %
        int(1e9 + 7);

    return dp_[i][j];
  }

private:
  int dp_[1000][1000] = {};
};

