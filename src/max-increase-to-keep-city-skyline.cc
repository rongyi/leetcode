// https://leetcode.com/problems/max-increase-to-keep-city-skyline/description/

#include "xxx.h"

class Solution {
public:
  int maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
    const int m = grid.size();
    const int n = grid[0].size();

    vector<int> row(m, 0);
    vector<int> col(n, 0);
    int ret = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        row[i] = max(row[i], grid[i][j]);
        col[j] = max(col[j], grid[i][j]);
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ret += min(row[i] - grid[i][j], col[j] - grid[i][j]);
      }
    }


    return ret;
  }
};
