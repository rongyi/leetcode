// http://leetcode.com/problems/range-sum-query-2d-immutable/description/
#include "xxx.hpp"

class NumMatrix {
public:
  NumMatrix(vector<vector<int>> matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();

    dp_ = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        dp_[i + 1][j + 1] =
            matrix[i][j] + dp_[i + 1][j] + dp_[i][j + 1] - dp_[i][j];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return dp_[row2 + 1][col2 + 1] - dp_[row2 + 1][col1] - dp_[row1][col2 + 1] +
           dp_[row1][col1];
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
