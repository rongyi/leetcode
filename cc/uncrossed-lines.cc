// http://leetcode.com/problems/uncrossed-lines/description/
#include "xxx.h"

class Solution {
public:
  int maxUncrossedLines(vector<int> &A, vector<int> &B) {
    vector<vector<int>> dp(A.size(), vector<int>(B.size(), -1));
    return dfs(A, B, 0, 0, dp);
  }
  int dfs(vector<int> &A, vector<int> &B, int valid_i, int valid_j, vector<vector<int>> &dp) {
    if (valid_i >= A.size() || valid_j >= B.size()) {
      return 0;
    }
    if (dp[valid_i][valid_j] != -1) {
      return dp[valid_i][valid_j];
    }
    auto nj = valid_j;
    // 找一条从A[valid_i] ==> B[x]的一条线，
    while (nj < B.size() && B[nj] != A[valid_i]) {
      ++nj;
    }
    // 可以划也可以不划， 不划约束条件不变，划了，下一个有效的，就是这个nj + 1的位置了，因为不能
    // 回头，否则就相交了
    int cross = (nj < B.size() ? 1 : 0) + dfs(A, B, valid_i + 1, nj + 1, dp);
    int untouch = dfs(A, B, valid_i + 1, valid_j, dp);
    dp[valid_i][valid_j] = max(cross, untouch);

    return dp[valid_i][valid_j];
  }
};
