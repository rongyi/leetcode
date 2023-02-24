// http://leetcode.com/problems/search-a-2d-matrix/description/
#include "xxx.hpp"

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int l = 0;
    int r = m * n - 1;
    while (l <= r) {
      auto mid = l + (r - l) / 2;
      int i = mid / n;
      int j = mid % n;
      if (matrix[i][j] == target) {
        return true;
      } else if (matrix[i][j] < target) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return false;
  }
};

