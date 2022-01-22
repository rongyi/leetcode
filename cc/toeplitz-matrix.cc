// https://leetcode.com/problems/toeplitz-matrix/description/
#include "xxx.hpp"

class Solution {
public:
  bool isToeplitzMatrix(vector<vector<int>> &matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    // last element no need to check, only one
    for (int j = 0; j < n - 1; j++) {
      int cpj = j;
      int cur = matrix[0][cpj];
      for (int i = 1; i < m; ++i) {
        if (cpj + 1 < n) {
          if (matrix[i][++cpj] != cur) {
            return false;
          }
        }
      }
    }

    for (int i = 1; i < m - 1; ++i) {
      int cpi = i;
      int cur = matrix[cpi][0];
      for (int j = 1; j < n; ++j) {
        if (cpi + 1 < m) {
          if (matrix[++cpi][j] != cur) {
            return false;
          }
        }
      }
    }

    return true;
  }
};

int main() {
  Solution so;
  vector<vector<int>> matrix{{1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2}};
  auto ret = so.isToeplitzMatrix(matrix);
  cout << ret << endl;
}
