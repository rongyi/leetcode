// http://leetcode.com/problems/search-a-2d-matrix-ii/description/
#include "xxx.hpp"

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int i = 0;
    int j = n - 1;
    while (i < m && j >= 0) {
      if (matrix[i][j] == target) {
        return true;
      }
      // current matrix[i][j] is the minimum for
      // current column j, so every nums below current
      // column is bigger than target, we don't need
      // to search this column
      // just cut of this column
      if (target < matrix[i][j]) {
        j--;
      } else {
        // matrix[i][j] is the biggest numer in current row
        // if target still bigger than this one
        // then current row is no need to serach
        i++;
      }
    }
    return false;
  }
};
