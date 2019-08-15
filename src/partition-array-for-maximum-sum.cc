// http://leetcode.com/problems/partition-array-for-maximum-sum/description/
#include "xxx.h"

class Solution {
public:
  int maxSumAfterPartitioning(vector<int> &A, int K) {
    const int n = A.size();

    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i) {
      int cur_max = 0;
      for (int k = 1; k <= K && i - k + 1 >= 0; ++k) {
        cur_max = max(cur_max, A[i - k + 1]);
        dp[i] = max(dp[i], (i >= k ? dp[i - k] : 0) + cur_max * k);
      }
    }

    return dp[n - 1];
  }
};
