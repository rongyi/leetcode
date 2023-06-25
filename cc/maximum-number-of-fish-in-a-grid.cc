// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/
#include "xxx.hpp"

class Solution {
public:
  int findMaxFish(vector<vector<int>> &grid) {
    dirs_ = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int ret = 0;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] != 0) {
          ret = max(ret, dfs(i, j, grid, m, n));
        }
      }
    }

    return ret;
  }

private:
  int dfs(int x, int y, vector<vector<int>> &grid, int m, int n) {
    int total = grid[x][y];
    // no visited cache, jsut clear it
    grid[x][y] = 0;

    for (int d = 0; d < 4; d++) {
      auto nx = x + dirs_[d][0];
      auto ny = y + dirs_[d][1];
      if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == 0) {
        continue;
      }
      total += dfs(nx, ny, grid, m, n);
    }

    return total;
  }

private:
  vector<vector<int>> dirs_;
};
