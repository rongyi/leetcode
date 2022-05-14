// https://leetcode.com/problems/count-unguarded-cells-in-the-grid/
#include "xxx.hpp"

class Solution {
public:
  int countUnguarded(int m, int n, vector<vector<int>> &guards,
                     vector<vector<int>> &walls) {
    // we count 0
    int ret = 0;
    vector<vector<int>> grid(m, vector<int>(n, 0));
    for (auto &gd : guards) {
      grid[gd[0]][gd[1]] = 10;
    }
    for (auto &w : walls) {
      grid[w[0]][w[1]] = 100;
    }

    for (auto &g : guards) {
      int cur_row = g[0];
      int cur_col = g[1];
      for (int j = cur_col + 1; j < n; ++j) {
        if (grid[cur_row][j] == 0) {
          grid[cur_row][j] = 1000;
        } else if (grid[cur_row][j] == 100 || grid[cur_row][j] == 10) {
          // meet a wall
          break;
        }
      }
      for (int j = cur_col - 1; j >= 0; --j) {
        if (grid[cur_row][j] == 0) {
          grid[cur_row][j] = 1000;
        } else if (grid[cur_row][j] == 100 || grid[cur_row][j] == 10) {
          // meet a wall
          break;
        }
      }
      for (int i = cur_row + 1; i < m; ++i) {
        if (grid[i][cur_col] == 0) {
          grid[i][cur_col] = 1000;
        } else if (grid[i][cur_col] == 100 || grid[i][cur_col] == 10) {
          // meet a wall
          break;
        }
      }
      for (int i = cur_row - 1; i >= 0; --i) {
        if (grid[i][cur_col] == 0) {
          grid[i][cur_col] = 1000;
        } else if (grid[i][cur_col] == 100 || grid[i][cur_col] == 10) {
          // meet a wall
          break;
        }
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0) {
          ++ret;
        }
      }
    }

    return ret;
  }
};
