// http://leetcode.com/problems/island-perimeter/description/
#include "xxx.h"

class Solution {
public:
  int islandPerimeter(vector<vector<int>> &grid) {
    int ret = 0;
    const int m = grid.size();
    if (m == 0) {
      return 0;
    }
    const int n = grid[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          ret += 4;
          if (i + 1 < m && grid[i + 1][j] == 1) {
            --ret;
          }
          if (i - 1 >= 0 && grid[i - 1][j] == 1) {
            --ret;
          }
          if (j + 1 < n && grid[i][j + 1] == 1) {
            --ret;
          }
          if (j - 1 >= 0 && grid[i][j - 1] == 1) {
            --ret;
          }
        }
      }
    }

    return ret;
  }
};
