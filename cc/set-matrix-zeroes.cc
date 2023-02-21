// http://leetcode.com/problems/set-matrix-zeroes/description/
#include "xxx.hpp"

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    // first row and first column has zero?
    bool row = false;
    bool col = false;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0) {
          if (i == 0) {
            row = true;
          }
          if (j == 0) {
            col = true;
          }
          // bubble to top & left
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (matrix[0][j] == 0 || matrix[i][0] == 0) {
          matrix[i][j] = 0;
        }
      }
    }
    if (row) {
      for (int j = 0; j < n; j++) {
        matrix[0][j] = 0;
      }
    }
    if (col) {
      for (int i = 0; i < m; i++) {
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
