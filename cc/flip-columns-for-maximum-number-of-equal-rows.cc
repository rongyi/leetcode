// http://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/description/
#include "xxx.hpp"

class Solution {
public:
  // Find the i-th row, which has the most same or totaly different rows in the
  // matrix.
  int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<int> flip(n, 0);
    int ret = 0;
    for (int i = 0; i < m; ++i) {
      int cur_count = 0;
      for (int j = 0; j < n; ++j) {
        flip[j] = 1 - matrix[i][j];
      }
      for (int k = 0; k < m; ++k) {
        if (matrix[k] == matrix[i] || matrix[k] == flip) {
          ++cur_count;
        }
      }

      ret = max(ret, cur_count);
    }

    return ret;
  }
};
