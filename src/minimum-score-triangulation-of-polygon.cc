// http://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/
#include "xxx.h"

class Solution {
public:
  int minScoreTriangulation(vector<int> &A) {
    vector<vector<int>> dp(50, vector<int>(50, 0));

    recur(A, 0, A.size() - 1, dp);

    return dp[0][A.size() - 1];
  }

private:
  int recur(vector<int> &A, int i, int j, vector<vector<int>> &dp) {
    if (dp[i][j] != 0) {
      return dp[i][j];
    }
    int ret = 0;
    for (auto k = i + 1; k < j; ++k) {
      ret = min(ret == 0 ? numeric_limits<int>::max() : ret,
                recur(A, i, k, dp) + A[i] * A[k] * A[j] + recur(A, k, j, dp));
    }
    dp[i][j] = ret;

    return dp[i][j];
  }
};
