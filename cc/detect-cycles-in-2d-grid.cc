// http://leetcode.com/problems/detect-cycles-in-2d-grid/description/
#include "xxx.h"

class Solution {
public:
  bool containsCycle(vector<vector<char>> &grid) {
    dirs_ = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    const int m = grid.size();
    const int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!visited[i][j]) {
          if (dfs(grid, m, n, i, j, -1, -1, visited, grid[i][j])) {
            return true;
          }
        }
      }
    }

    return false;
  }

private:
  bool dfs(vector<vector<char>> &grid, int m, int n, int x, int y, int prevx,
           int prevy, vector<vector<bool>> &vis, char cur) {
    vis[x][y] = true;
    for (auto &d : dirs_) {
      auto nx = x + d[0];
      auto ny = y + d[1];
      // valid region
      if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] != cur) {
        continue;
      }
      // no comback
      if (nx == prevx && ny == prevy) {
        continue;
      }

      if (vis[nx][ny]) {
        return true;
      } else if (dfs(grid, m, n, nx, ny, x, y, vis, cur)) {
        return true;
      }
    }

    return false;
  }

private:
  vector<vector<int>> dirs_;
};
