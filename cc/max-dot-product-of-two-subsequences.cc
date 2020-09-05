// http://leetcode.com/problems/max-dot-product-of-two-subsequences/description/
#include "xxx.h"

class Solution {
public:
  // https://leetcode.com/problems/max-dot-product-of-two-subsequences/discuss/648261/C%2B%2BPython-Simple-DP
  int maxDotProduct(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size();
    int n = nums2.size();

    vector<vector<int>> dp(m + 1,
                           vector<int>(n + 1, numeric_limits<int>::min()));
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        dp[i][j] = max(dp[i][j], dp[i][j - 1]);
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
        dp[i][j] = max(dp[i][j],
                       max(dp[i - 1][j - 1], 0) + nums1[i - 1] * nums2[j - 1]);
      }
    }

    return dp[m][n];
  }
};
