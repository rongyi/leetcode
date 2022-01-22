// http://leetcode.com/problems/longest-arithmetic-sequence/description/
#include "xxx.hpp"

class Solution {
public:
  int longestArithSeqLength(vector<int> &A) {
    // dp[diff][index]
    unordered_map<int, unordered_map<int, int>> dp;
    int ret = 2;
    const int n = A.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int d = A[j] - A[i];
        dp[d][j] = dp[d].count(i) ? dp[d][i] + 1 : 2;

        ret = max(ret, dp[d][j]);
      }
    }

    return ret;
  }
};
