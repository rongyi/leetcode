// http://leetcode.com/problems/ones-and-zeroes/description/
#include "xxx.hpp"

class Solution {
public:
  int findMaxForm(vector<string> &strs, int m, int n) {
    // m个0
    // n个1
    const int len = strs.size();
    vector<vector<vector<int>>> dp(
        len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

    for (int i = 1; i <= len; i++) {
      for (int j = 0; j <= m; ++j) {
        for (int k = 0; k <= n; ++k) {
          int ones = count(strs[i - 1].begin(), strs[i - 1].end(), '1');
          int zeros = strs[i - 1].size() - ones;
          // 前面已经用完j个0，k个1的这种case
          auto cur_ret = dp[i - 1][j][k];
          if (zeros <= j && ones <= k) {
            // 前面用了 j -zero个0 和
            // k - ones个1，那么加上当前这个str又多了一种方法来凑
            cur_ret = max(cur_ret, dp[i - 1][j - zeros][k - ones] + 1);
          }
          dp[i][j][k] = cur_ret;
        }
      }
    }
    return dp[len][m][n];
  }
};
