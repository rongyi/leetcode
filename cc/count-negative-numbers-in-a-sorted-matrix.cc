// http://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/
#include "xxx.hpp"

class Solution {
public:
  int countNegatives(vector<vector<int>> &grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    int ret = 0;
    int i = m - 1;
    int j = 0;
    while (i >= 0 && j < n) {
      if (grid[i][j] < 0) {
        --i;
        ret += n - j;
      } else {
        ++j;
      }
    }

    return ret;
  }
};
