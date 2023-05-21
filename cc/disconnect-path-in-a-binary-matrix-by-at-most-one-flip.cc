// https://leetcode.com/problems/disconnect-path-in-a-binary-matrix-by-at-most-one-flip/
#include "xxx.hpp"

class Solution {
public:
  bool isPossibleToCutPath(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    bool first_round = dfs(grid, m, n, 0, 0);
    if (!first_round) {
      return true;
    }
    grid[0][0] = 1;

    return !dfs(grid, m, n, 0, 0);
  }
  bool dfs(vector<vector<int>> &grid, int m, int n, int x, int y) {
    if (x >= m || y >= n || grid[x][y] == 0) {
      return false;
    }
    if (x == m - 1 && y == n - 1) {
      return true;
    }

    grid[x][y] = 0;

    return dfs(grid, m, n, x + 1, y) || dfs(grid, m, n, x, y + 1);
  }
};
