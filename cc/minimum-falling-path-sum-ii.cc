// http://leetcode.com/problems/minimum-falling-path-sum-ii/description/
#include "xxx.hpp"

class Solution {
public:
  int minFallingPathSum(vector<vector<int>> &arr) {
    const int n = arr.size();
    // 从最后面开始倒推
    for (int r = n - 2; r >= 0; r--) {
      for (int j = 0; j < n; j++) {
        int m = numeric_limits<int>::max();
        for (int k = 0; k < j; k++) {
          m = min(m, arr[r + 1][k]);
        }
        for (int k = j + 1; k < n; k++) {
          m = min(m, arr[r + 1][k]);
        }
        arr[r][j] += m;
      }
    }
    int ret = numeric_limits<int>::max();

    for (int j = 0; j < n; j++) {
      ret = min(ret, arr[0][j]);
    }

    return ret;
  }
};
