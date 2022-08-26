// https://leetcode.com/problems/equal-row-and-column-pairs/
#include "xxx.hpp"

class Solution {
public:
  int equalPairs(vector<vector<int>> &grid) {
    int sz = grid.size();
    int ret = 0;
    for (int i = 0; i < sz; ++i) {
      for (int j = 0; j < sz; ++j) {
        int k = 0;
        for (; k < sz; ++k) {
          if (grid[i][k] != grid[k][j]) {
            break;
          }
        }
        if (k == sz) {
          ret++;
        }
      }
    }

    return ret;
  }
};
