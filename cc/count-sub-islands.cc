// http://leetcode.com/problems/count-sub-islands/description/
#include "xxx.h"

class Solution {
public:
  int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
    int m = grid1.size();
    int n = grid1[0].size();
    int ret = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid2[i][j] == 1) {
          bool cur_valid = true;
          dfs(grid1, grid2, i, j, cur_valid);

          ret += cur_valid;
        }
      }
    }

    return ret;
  }

private:
  void dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int x, int y,
           bool &valid) {
    int m = grid1.size();
    int n = grid1[0].size();

    // out of bound?
    if (x < 0 || x >= m || y < 0 || y >= n) {
      return;
    }
    // but grid1 not valid
    if (grid2[x][y] == 1 && grid1[x][y] == 0) {
      valid = false;
      // don't return, to make all element in this island invalid
    }
    if (grid2[x][y] == 0) {
      return;
    }
    // visited mark
    grid2[x][y] = 0;

    dfs(grid1, grid2, x + 1, y, valid);
    dfs(grid1, grid2, x - 1, y, valid);
    dfs(grid1, grid2, x, y + 1, valid);
    dfs(grid1, grid2, x, y - 1, valid);
  }
};
