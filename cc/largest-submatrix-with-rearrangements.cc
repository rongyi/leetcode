// http://leetcode.com/problems/largest-submatrix-with-rearrangements/description/
#include "xxx.h"

class Solution {
public:
  int largestSubmatrix(vector<vector<int>> &matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();

    for (int j = 0; j < n; ++j) {
      for (int i = 1; i < m; ++i) {
        if (matrix[i][j] != 0) {
          matrix[i][j] += matrix[i - 1][j];
        }
      }
    }

    int ret = 0;
    for (int i = 0; i < m; ++i) {
      sort(matrix[i].begin(), matrix[i].end(), greater<int>());

      for (int j = 0; j < n; ++j) {
        ret = max(ret, matrix[i][j] * (j + 1));
      }
    }
    return ret;
  }
};
