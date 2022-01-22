// https://leetcode.com/problems/rotate-image/
#include "xxx.hpp"

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    const int n = matrix.size();
    int k = n - 1;
    // 辅对角线翻转
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < k; j++) {
        auto ri = n - j - 1;
        auto rj = n - i - 1;

        swap(matrix[i][j], matrix[ri][rj]);
      }
      k--;
    }
    for (int i = 0; i < n / 2; ++i) {
      for (int j = 0; j < n; ++j) {
        swap(matrix[i][j], matrix[n - i - 1][j]);
      }
    }
  }
};
