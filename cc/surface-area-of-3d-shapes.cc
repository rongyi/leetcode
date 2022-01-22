// http://leetcode.com/problems/surface-area-of-3d-shapes/description/
#include "xxx.hpp"

class Solution {
public:
  int surfaceArea(vector<vector<int>> &grid) {
    const int n = grid.size();
    int ret = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j]) {
          ret += grid[i][j] * 4 + 2;
          if (i > 0) {
            ret -= min(grid[i][j], grid[i - 1][j]) * 2;
          }
          if (j > 0) {
            ret -= min(grid[i][j], grid[i][j - 1]) * 2;
          }
        }
      }
    }
    return ret;
  }
};
