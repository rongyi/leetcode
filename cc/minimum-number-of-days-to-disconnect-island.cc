// http://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/description/
#include "xxx.hpp"

class Solution {
public:
  int minDays(vector<vector<int>> &grid) {
    dirs_ = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    m_ = grid.size();
    n_ = grid[0].size();

    auto islands = count_islands(grid);
    if (islands == 0 || islands > 1) {
      return 0;
    } else {
      for (int i = 0; i < m_; ++i) {
        for (int j = 0; j < n_; ++j) {
          if (grid[i][j]) {
            grid[i][j] = 0;
            islands = count_islands(grid);
            if (islands > 1 || islands == 0) {
              return 1;
            }
            // restore back
            grid[i][j] = 1;
          }
        }
      }
    }
    return 2;
  }

private:
  void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &vis) {
    vis[x][y] = 1;
    for (auto &d : dirs_) {
      auto nx = x + d[0];
      auto ny = y + d[1];
      if (nx < 0 || nx >= m_ || ny < 0 || ny >= n_) {
        continue;
      }

      if (!vis[nx][ny] && grid[nx][ny]) {
        dfs(nx, ny, grid, vis);
      }
    }
  }
  int count_islands(vector<vector<int>> &grid) {
    int ret = 0;
    vector<vector<int>> vis(m_, vector<int>(n_, 0));
    for (int i = 0; i < m_; ++i) {
      for (int j = 0; j < n_; ++j) {
        if (!vis[i][j] && grid[i][j]) {
          ++ret;
          dfs(i, j, grid, vis);
        }
      }
    }

    return ret;
  }

private:
  vector<vector<int>> dirs_;
  int m_;
  int n_;
};
