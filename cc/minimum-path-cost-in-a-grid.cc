// https://leetcode.com/problems/minimum-path-cost-in-a-grid/
#include "xxx.hpp"

class Solution {
public:
  int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> cache(m, vector<int>(n, numeric_limits<int>::max()));
    for (int j = 0; j < n; ++j) {
      cache[0][j] = 0;
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
          cache[i][j] = min(cache[i][j], cache[i - 1][k] + grid[i - 1][k] +
                                             moveCost[grid[i - 1][k]][j]);
        }
      }
    }
    int ret = numeric_limits<int>::max();
    for (int j = 0; j < n; ++j) {
      cache[m - 1][j] += grid[m - 1][j];
      ret = min(ret, cache[m - 1][j]);
    }

    return ret;
  }
};
