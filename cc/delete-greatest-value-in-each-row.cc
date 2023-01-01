// https://leetcode.com/problems/delete-greatest-value-in-each-row/
#include "xxx.hpp"

class Solution {
public:
  int deleteGreatestValue(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; ++i) {
      sort(rbegin(grid[i]), rend(grid[i]));
    }
    int ret = 0;

    for (int j = 0; j < n; ++j) {
      int cur = 0;
      for (int i = 0; i < m; ++i) {
        cur = max(cur, grid[i][j]);
      }

      ret += cur;
    }

    return ret;
  }
};
