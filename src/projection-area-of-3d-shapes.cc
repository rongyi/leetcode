// http://www.lintcode.com/zh-cn/problem/projection-area-of-3d-shapes

#include "one.h"

class Solution {
public:
  int projectionArea(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    vector<int> rowmax(m, 0);
    vector<int> colmax(n, 0);
    int ret = 0;

    for (int i = 0; i < m ; ++i) {
      for (int j = 0; j < n; ++j) {
        rowmax[i] = max(grid[i][j], rowmax[i]);
        if (grid[i][j] != 0) {
          ++ret;
        }
      }
    }
    for (int j = 0; j < n; ++j) {
      for (int i = 0; i < m; ++i) {
        colmax[j] = max(colmax[j], grid[i][j]);
      }
    }

    ret = accumulate(rowmax.begin(), rowmax.end(), ret);
    ret = accumulate(colmax.begin(), colmax.end(), ret);

    return ret;
  }
};
