// http://www.lintcode.com/zh-cn/problem/largest-plus-sign
#include "one.h"

class Solution {
public:
  int orderOfLargestPlusSign(int N, vector<vector<int>> &mines) {
    // construct the matrix
    vector<vector<int>> matrix(N, vector<int>(N, 1));
    for (auto cord : mines) {
      matrix[cord[0]][cord[1]] = 0;
    }
    int ret = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        int k = 0;

        while (canExpand(matrix, i, j, k, N)) {
          ++k;
        }
        ret = max(ret, k);
      }
    }

    return ret;
  }

private:
  bool canExpand(vector<vector<int>> &matrix, int i, int j, int k,
                 const int n) {
    // boundary check
    if (i + k >= n || i - k < 0 || j + k >= n || j - k < 0) {
      return false;
    }
    return matrix[i + k][j] && matrix[i - k][j] && matrix[i][j - k] && matrix[i][j + k];
  }
};

int main() {

}
