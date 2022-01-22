// http://www.lintcode.com/zh-cn/problem/largest-plus-sign
#include "xxx.hpp"

class Solution {
public:
  // 除了暴力之外还有一种就是算各个方向上的当前值前面有几个1
  // 前后左右四个方向上连续出现1的个数
  int orderOfLargestPlusSign(int N, vector<vector<int>> &mines) {
    vector<vector<int>> dp(N, vector<int>(N, 0));
    // construct sparse matrix
    unordered_set<int> matrix;
    for (auto cord : mines) {
      matrix.insert(cord[0] * N + cord[1]);
    }

    int ret = 0;
    int cnt = 0;
    // colum
    for (int j = 0; j < N; ++j) {
      cnt = 0;
      for (int i = 0; i < N; ++i) {
        cnt = matrix.count(i * N + j) ? 0 : cnt + 1;
        dp[i][j] = cnt;
      }
      cnt = 0;
      for (int i = N - 1; i >= 0; --i) {
        cnt = matrix.count(i * N + j) ? 0 : cnt + 1;
        dp[i][j] = min(cnt, dp[i][j]);
      }
    }
    // row
    for (int i = 0; i < N; ++i) {
      cnt = 0;
      for (int j = 0; j < N; ++j) {
        cnt = matrix.count(i * N + j) ? 0 : cnt + 1;
        dp[i][j] = min(dp[i][j], cnt);
      }
      cnt = 0;
      for (int j = N - 1; j >= 0; --j) {
        cnt = matrix.count(i * N + j) ? 0 : cnt + 1;
        dp[i][j] = min(dp[i][j], cnt);
        ret = max(ret, dp[i][j]);
      }
    }

    return ret;
  }

  int orderOfLargestPlusSignBruteForce(int N, vector<vector<int>> &mines) {
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
    return matrix[i + k][j] && matrix[i - k][j] && matrix[i][j - k] &&
           matrix[i][j + k];
  }
};

int main() {}
