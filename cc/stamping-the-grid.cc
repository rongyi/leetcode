// https://leetcode.com/problems/stamping-the-grid/
#include "xxx.hpp"

class Solution {
public:
  bool possibleToStamp(vector<vector<int>> &grid, int h, int w) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> stamp(m, vector<int>(n, 0));
    auto grid_prefix = prefixSum(grid, m, n);
    for (int i = h - 1; i < m; ++i) {
      for (int j = w - 1; j < n; ++j) {
        stamp[i][j] = sum2d(grid_prefix, i - h + 1, j - w + 1, i, j) == 0;
      }
    }
    auto stamp_prefix = prefixSum(stamp, m, n);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0 && sum2d(stamp_prefix, i, j, min(m - 1, i + h - 1),
                                     min(n - 1, j + w - 1)) == 0) {
          return false;
        }
      }
    }
    return true;
  }

private:
  vector<vector<int>> prefixSum(vector<vector<int>> &matrix, int m, int n) {
    vector<vector<int>> ret(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ret[i + 1][j + 1] =
            matrix[i][j] + ret[i + 1][j] + ret[i][j + 1] - ret[i][j];
      }
    }

    return ret;
  }
  // sum in [r1, c1] [r2, c2] included
  int sum2d(vector<vector<int>> &prefix, int r1, int c1, int r2, int c2) {
    return prefix[r2 + 1][c2 + 1] - prefix[r1][c2 + 1] - prefix[r2 + 1][c1] +
           prefix[r1][c1];
  }
};
