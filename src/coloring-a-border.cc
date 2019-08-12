// http://leetcode.com/problems/coloring-a-border/description/
#include "xxx.h"

class Solution {
public:
  vector<vector<int>> colorBorder(vector<vector<int>> &grid, int r0, int c0,
                                  int color) {
    m_ = grid.size();
    n_ = grid[0].size();
    dfs(grid, r0, c0, grid[r0][c0]);

    for (int i = 0; i < m_; ++i) {
      for (int j = 0; j < n_; ++j) {
        if (grid[i][j] < 0) {
          // 重新染色
          grid[i][j] = color;
        }
      }
    }
    return grid;
  }
  void dfs(vector<vector<int>> &grid, int x, int y, int cl) {
    if (x < 0 || x >= m_ || y < 0 || y >= n_ || grid[x][y] != cl) {
      return;
    }

    grid[x][y] = -cl;

    dfs(grid, x + 1, y, cl);
    dfs(grid, x - 1, y, cl);
    dfs(grid, x, y + 1, cl);
    dfs(grid, x, y - 1, cl);

    // 看是否在中间
    if (x > 0 && x < m_ - 1 && y > 0 && y < n_ - 1) {
      auto around = abs(grid[x - 1][y]) == cl && abs(grid[x + 1][y]) == cl &&
                    abs(grid[x][y + 1]) == cl && abs(grid[x][y - 1]) == cl;
      if (around) {
        // 恢复回来
        grid[x][y] = cl;
      }
    }
  }

private:
  int m_;
  int n_;
};
