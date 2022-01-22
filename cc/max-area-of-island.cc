// http://leetcode.com/problems/max-area-of-island/description/
#include "xxx.hpp"

class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    const int m = grid.size();
    if (m == 0) {
      return 0;
    }
    const int n = grid[0].size();
    if (n == 0) {
      return 0;
    }
    m_ = m;
    n_ = n;
    dirs_ = vector<vector<int>>{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int ret = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          int cur_count = 0;
          vector<vector<bool>> visited(m, vector<bool>(n, 0));
          dfs(grid, visited, i, j, cur_count);
          ret = max(ret, cur_count);
        }
      }
    }
    return ret;
  }

private:
  void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x,
           int y, int &count) {
    if (x < 0 || x >= m_ || y < 0 || y >= n_ || visited[x][y] ||
        grid[x][y] != 1) {
      return;
    }
    count++;
    visited[x][y] = 1;
    grid[x][y] = 0;
    for (int i = 0; i < 4; i++) {
      int nx = x + dirs_[i][0];
      int ny = y + dirs_[i][1];
      dfs(grid, visited, nx, ny, count);
    }
  }

private:
  int m_;
  int n_;
  vector<vector<int>> dirs_;
};
