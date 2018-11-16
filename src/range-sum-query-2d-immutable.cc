// http://leetcode.com/problems/range-sum-query-2d-immutable/description/
#include "simpleone.h"

class NumMatrix {
public:
  NumMatrix(vector<vector<int>> matrix) {
    const int m = matrix.size();
    if (m == 0) {
      return;
    }
    const int n = matrix[0].size();
    dp_ = vector<vector<int>>(m, vector<int>(n, 0));
    // update first row
    dp_[0][0] = matrix[0][0];
    for (int j = 1; j < n; j++) {
      dp_[0][j] = dp_[0][j - 1] + matrix[0][j];
    }
    // update first col
    for (int i = 1; i < m; i++) {
      dp_[i][0] = dp_[i - 1][0] + matrix[i][0];
    }
    // calculate
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        // .   .
        // .  i, j
        // 减去多加的部分
        dp_[i][j] = dp_[i - 1][j] + dp_[i][j - 1] - dp_[i - 1][j - 1] + matrix[i][j];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    if (row1 == 0 && col1 == 0) {
      return dp_[row2][col2];
    }
    if (row1 == 0) {
      return dp_[row2][col2] - dp_[row2][col1 - 1];
    }
    if (col1 == 0) {
      return dp_[row2][col2] - dp_[row1 - 1][col2];
    }
    return dp_[row2][col2] + dp_[row1 - 1][col1 - 1] - dp_[row1 - 1][col2] -
           dp_[row2][col1 - 1];
  }

private:
  vector<vector<int>> dp_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */

int main() {
  vector<vector<int>> input{{3, 0, 1, 4, 2},
                            {5, 6, 3, 2, 1},
                            {1, 2, 0, 1, 5},
                            {4, 1, 0, 1, 7},
                            {1, 0, 3, 0, 5}};
  NumMatrix so(input);
  auto ret = so.sumRegion(2, 1, 4, 3);
  cout << ret << endl;
}
