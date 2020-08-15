// http://leetcode.com/problems/search-a-2d-matrix-ii/description/
#include "xxx.h"

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    const int m = matrix.size();
    if (m == 0) {
      return false;
    }

    const int n = matrix[0].size();
    if (n == 0) {
      return false;
    }
    // 这题没办法折半的，只能在O(n)的基础上快一点，一旦比一行的最小的还小，那肯定不在这一行上
    // 最小值在左上角， 最大值在右下角
    if (target < matrix[0][0] || target > matrix[m - 1][n - 1]) {
      return false;
    }
    for (int i = m - 1, j = 0; i >= 0 && j < n;) {
      if (matrix[i][j] == target) {
        return true;
      }
      if (matrix[i][j] < target) {
        j++;
      } else {
        i--;
      }
    }
    return false;
  }
};
