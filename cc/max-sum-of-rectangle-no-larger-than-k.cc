// http://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/description/
#include "xxx.h"

class Solution {
public:
  int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
    const int m = matrix.size();
    if (m == 0) {
      return 0;
    }
    const int n = matrix[0].size();
    if (n == 0) {
      return 0;
    }
    // 小于k的最大值，所以这里选最小的
    int ret = numeric_limits<int>::min();
    int sum[m][n];

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        auto tmp = matrix[i][j];
        if (i > 0) {
          tmp += sum[i - 1][j];
        }
        if (j > 0) {
          tmp += sum[i][j - 1];
        }
        // 多加的部分再减回去
        if (i > 0 && j > 0) {
          tmp -= sum[i - 1][j - 1];
        }
        sum[i][j] = tmp;

        for (int r = 0; r <= i; r++) {
          for (int c = 0; c <= j; c++) {
            auto tmp = sum[i][j];
            // x被减了两次，加回来一次
            // x -   -   0
            // - r,c 0   0
            // - 0   i,j 0
            // 0 0   0   0
            if (r > 0) {
              tmp -= sum[r - 1][j];
            }
            if (c > 0) {
              tmp -= sum[i][c - 1];
            }
            // 多减的加回来
            if (r > 0 && c > 0) {
              tmp += sum[r - 1][c - 1];
            }
            if (tmp <= k) {
              ret = max(ret, tmp);
            }
          }
        }
      }
    }

    return ret;
  }

  int maxSumSubmatrixNexLevel(vector<vector<int>> &matrix, int k) {
    const int m = matrix.size();
    const int n = matrix[0].size();

    int maxsk = numeric_limits<int>::min();
    int cursum = 0;

    for (int l = 0; l < n; l++) {
      // 这是叠加到一起按照一维数组的方法来做
      vector<int> sum(m);
      for (int c = l; c < n; c++) {
        cursum = 0;
        set<int> os;
        os.insert(0);
        for (int j = 0; j < m; j++) {
          sum[j] += matrix[j][c];
          cursum += sum[j];
          auto it = os.lower_bound(cursum - k);
          if (it != os.end())
            maxsk = max(maxsk, cursum - *it);
          os.insert(cursum);
        }
      }
    }
    return maxsk;
  }
};

int main() {
  Solution so;
  vector<vector<int>> matrix{{1, 0, 1}, {0, -2, 3}};
  auto ret = so.maxSumSubmatrix(matrix, 2);
  cout << ret << endl;
}
