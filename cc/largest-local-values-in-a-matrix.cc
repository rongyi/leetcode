// https://leetcode.com/problems/largest-local-values-in-a-matrix/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> largestLocal(vector<vector<int>> &grid) {
    int sz = grid.size();
    vector<vector<int>> ret(sz - 2, vector<int>(sz - 2, 0));

    // yes, itpassed
    for (int i = 0; i + 2 < sz; ++i) {
      for (int j = 0; j + 2 < sz; ++j) {
        int cur_max = 0;
        for (int k = 0; k < 3; ++k) {
          for (int l = 0; l < 3; ++l) {
            cur_max = max(cur_max, grid[i + k][j + l]);
          }
        }
        ret[i][j] = cur_max;
      }
    }

    return ret;
  }
};
