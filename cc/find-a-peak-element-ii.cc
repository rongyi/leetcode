// http://leetcode.com/problems/find-a-peak-element-ii/description/

#include "xxx.h"

class Solution {
public:
  vector<int> findPeakGrid(vector<vector<int>> &mat) {
    int m = mat.size();
    int n = mat[0].size();
    int lo = 0;
    int hi = n - 1;

    while (lo <= hi) {
      auto mid = lo + (hi - lo) / 2;
      int max_row = 0;
      // find the max row in this mid column
      for (int i = 0; i < m; ++i) {
        if (mat[i][mid] > mat[max_row][mid]) {
          max_row = i;
        }
      }

      // bigger than two side
      if ((mid == 0 || mat[max_row][mid] > mat[max_row][mid - 1]) &&
          (mid == n - 1 || mat[max_row][mid] > mat[max_row][mid + 1])) {
        return {max_row, mid};
      } else if (mid > 0 && mat[max_row][mid] > mat[max_row][mid - 1]) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }

    return {-1, -1};
  }
};
