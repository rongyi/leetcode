// http://leetcode.com/problems/number-of-closed-islands/description/
#include "xxx.hpp"

class Solution {
public:
  int closedIsland(vector<vector<int>> &grid) {
    dirs_ = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int ret = 0;
    const int m = grid.size();
    const int n = grid[0].size();
    // 沿着边把iland全去掉，因为完全包围不包括边
    for (int i = 0; i < m; ++i) {
      fill(grid, i, 0);
      fill(grid, i, n - 1);
    }
    for (int j = 0; j < n; ++j) {
      fill(grid, 0, j);
      fill(grid, m - 1, j);
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0) {
          // 这一坨只会遇到一次
          ++ret;
          // 因为这里会清空这个iland
          fill(grid, i, j);
        }
      }
    }

    return ret;
  }

private:
  void fill(vector<vector<int>> &grid, int x, int y) {
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() ||
        grid[x][y] == 1) {
      return;
    }

    grid[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
      auto nx = x + dirs_[i][0];
      auto ny = y + dirs_[i][1];
      fill(grid, nx, ny);
    }
  }

private:
  vector<vector<int>> dirs_;
};
