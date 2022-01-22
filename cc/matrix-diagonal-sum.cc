// http://leetcode.com/problems/matrix-diagonal-sum/description/
#include "xxx.hpp"

class Solution {
public:
  int diagonalSum(vector<vector<int>> &mat) {
    int ret = 0;
    const int n = mat.size();
    for (int i = 0, j = n - 1; i < n; ++i, --j) {
      ret += mat[i][i];
      ret += mat[i][j];
    }
    if (n & 1) {
      ret -= mat[n / 2][n / 2];
    }

    return ret;
  }
};
