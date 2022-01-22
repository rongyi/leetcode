// http://leetcode.com/problems/unique-paths-iii/description/
#include "xxx.hpp"

class Solution {
public:
  int uniquePathsIII(vector<vector<int>> &grid) {
    int startx = 0;
    int starty = 0;
    m_ = grid.size();
    n_ = grid[0].size();
    int steps = 0;
    for (int i = 0; i < m_; i++) {
      for (int j = 0; j < n_; j++) {
        if (grid[i][j] == 1) {
          startx = i;
          starty = j;
        }
        if (grid[i][j] != -1) {
          ++steps;
        }
      }
    }
    return dfs(grid, startx, starty, 1, steps);
  }
  int dfs(vector<vector<int>> &grid, int x, int y, int cur_step,
          int total_steps) {
    if (x < 0 || x >= m_ || y < 0 || y >= n_ || grid[x][y] == -1) {
      return 0;
    }
    if (grid[x][y] == 2) {
      return (cur_step == total_steps) ? 1 : 0;
    }
    grid[x][y] = -1;
    int paths = dfs(grid, x + 1, y, cur_step + 1, total_steps) +
                dfs(grid, x - 1, y, cur_step + 1, total_steps) +
                dfs(grid, x, y + 1, cur_step + 1, total_steps) +
                dfs(grid, x, y - 1, cur_step + 1, total_steps);

    grid[x][y] = 0;
    return paths;
  }

private:
  int m_;
  int n_;
};
