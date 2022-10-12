// https://leetcode.com/problems/maximum-rows-covered-by-columns/
#include "xxx.hpp"

class Solution {
public:
  int maximumRows(vector<vector<int>> &matrix, int numSelect) {
    int m = matrix.size();
    int n = matrix[0].size();
    int ret = 0;
    // enumerate all col combinations
    for (int mask = 0; mask < (1 << n); ++mask) {
      int one_cnt = __builtin_popcount(mask);
      if (one_cnt > numSelect) {
        continue;
      }
      int cur = 0;
      for (int i = 0; i < m; ++i) {
        int j = 0;
        for (; j < n; ++j) {
          // this pos is not selected, should be zero
          // this pos is supposed to be zero
          if (matrix[i][j] && ((1 << j) & mask) == 0) {
            break;
          }
        }
        cur += (j == n);
      }
      ret = max(ret, cur);
    }

    return ret;
  }
};
