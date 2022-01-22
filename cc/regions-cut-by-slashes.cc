// http://leetcode.com/problems/regions-cut-by-slashes/description/
#include "xxx.hpp"

class Solution {
public:
  //  \ ==>
  // 1 0 0
  // 0 1 0
  // 0 0 1

  // / ==>
  // 0 0 1
  // 0 1 0
  // 1 0 0
  int regionsBySlashes(vector<string> &grid) {
    const int n = grid.size();
    vector<vector<int>> expand(n * 3, vector<int>(n * 3, 0));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '/') {
          expand[i * 3][j * 3 + 2] = 1;
          expand[i * 3 + 1][j * 3 + 1] = 1;
          expand[i * 3 + 2][j * 3] = 1;
        } else if (grid[i][j] == '\\') {
          expand[i * 3][j * 3] = 1;
          expand[i * 3 + 1][j * 3 + 1] = 1;
          expand[i * 3 + 2][j * 3 + 2] = 1;
        }
      }
    }
    int ret = 0;
    n_ = 3 * n;
    for (int i = 0; i < 3 * n; i++) {
      for (int j = 0; j < 3 * n; j++) {
        if (expand[i][j] == 0) {
          dfs(expand, i, j);
          ret++;
        }
      }
    }

    return ret;
  }

private:
  void dfs(vector<vector<int>> &grid, int x, int y) {
    if (x < 0 || x >= n_ || y < 0 || y >= n_ || grid[x][y] == 1) {
      return;
    }

    grid[x][y] = 1;
    dfs(grid, x + 1, y);
    dfs(grid, x - 1, y);
    dfs(grid, x, y + 1);
    dfs(grid, x, y - 1);
  }

private:
  int n_;
};

int main() { Solution so; }
