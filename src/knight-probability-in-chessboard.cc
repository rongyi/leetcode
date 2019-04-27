// http://leetcode.com/problems/knight-probability-in-chessboard/description/
#include "xxx.h"

class Solution {
public:
  double knightProbability(int N, int K, int r, int c) {
    vector<vector<vector<double>>> dp(
        K + 1, vector<vector<double>>(N, vector<double>(N, -1)));
    return recur(dp, N, K, r, c) / pow(8, K); // 样本空间这么大
  }

private:
  double recur(vector<vector<vector<double>>> &dp, int N, int k, int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N) {
      return 0.0;
    }
    if (k == 0) {
      return 1.0;
    }
    if (dp[k][r][c] != -1.0) {
      return dp[k][r][c];
    }
    dp[k][r][c] = 0.0;
    // 八个方向走，找出的规律
    // -1, -2 / -1, 2
    // 1, -2 / 1, 2
    // -2, -1 / -2, 1
    // 2, -1 / 2, 1
    // 八个方向的组合，而且 y == +-(3 - abs(x))
    for (int i = -2; i <= 2; i++) {
      if (i == 0) {
        continue;
      }
      dp[k][r][c] += recur(dp, N, k - 1, r + i, c + (3 - abs(i))) +
                     recur(dp, N, k - 1, r + i, c - (3 - abs(i)));
    }
    return dp[k][r][c];
  }
};
