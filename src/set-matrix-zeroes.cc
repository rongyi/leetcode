// http://leetcode.com/problems/set-matrix-zeroes/description/
#include "one.h"

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    // check first row and column should clear?
    // 把第一列和第一行作为缓存，以此来清理后续行列，之前做个标记表示是否要清理第一行
    // 和第一列
    bool clearrow = false;
    bool clearcol = false;
    for (int i = 0; i < m; ++i) {
      if (matrix[i][0] == 0) {
        clearcol = true;
        break;
      }
    }
    for (int j = 0; j < n; ++j) {
      if (matrix[0][j] == 0) {
        clearrow = true;
        break;
      }
    }
    // find and identify
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == 0) {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }

    for (int j = 1; j < n; ++j) {
      if (matrix[0][j] == 0) {
        for (int i = 0; i < m; ++i) {
          matrix[i][j] = 0;
        }
      }
    }

    for (int i = 1; i < m; ++i) {
      if (matrix[i][0] != 0) {
        continue;
      }
      for (int j = 0; j < n; ++j) {
        matrix[i][j] = 0;
      }
    }

    if (clearrow) {
      for (int j = 0; j < n; ++j) {
        matrix[0][j] = 0;
      }
    }
    if (clearcol) {
      for (int i = 0; i < m; ++i) {
        matrix[i][0] = 0;
      }
    }
  }
};
int main() {
  Solution so;
  vector<vector<int>> input{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  so.setZeroes(input);
  for (auto &v : input) {
    for (auto i : v) {
      cout << i << " ";
    }
    cout << endl;
  }
}
