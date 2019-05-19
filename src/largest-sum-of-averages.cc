// http://leetcode.com/problems/largest-sum-of-averages/description/
#include "xxx.h"

class Solution {
public:
  // https://leetcode.com/problems/largest-sum-of-averages/discuss/126003/C%2B%2B-DP-Simple-Solution-use-O(N*K)-Space-and-O(K*N2)-Time-With-Detailed-Explanation
  double largestSumOfAverages(vector<int> &A, int K) {
    const int n = A.size();
    vector<int> sum(n + 1, 0);
    // 数据放在 1..n 上
    for (int i = 0; i < n; i++) {
      sum[i + 1] = A[i] + sum[i];
    }
    // 只有一个group情况
    if (K <= 1) {
      return (1.0 * sum[n]) / n;
    }
    // 全部一刀一个切开
    if (K >= n) {
      return sum[n];
    }
    // 从前n个元素中取k个group
    vector<vector<double>> dp(n + 1, vector<double>(K + 1, 0.0));
    for (int i = 1; i <= n; i++) {
      // 取一个group就是这些元素的和
      dp[i][1] = (1.0 * sum[i]) / i;
    }
    for (int k = 2; k <= K; k++) {
      // -------j ------i
      // 用j分开
      // dp[i][k] = dp[j][k - 1] + (j + 1) --> i这段
      for (int i = k; i <= n; i++) {
        // >= k - 1的由来， j如果小于k - 1，那还分得出来k - 1块吗？不可能
        for (int j = i - 1; j >= k - 1; --j) {
          // 余下的 j + 1 --> i这段的平均值是 (sum [i] - sum[j + 1 - 1]) / (i - j - 1 + 1)
          dp[i][k] =
              max(dp[i][k], dp[j][k - 1] + 1.0 * (sum[i] - sum[j]) / (i - j));
        }
      }
    }
    return dp[n][K];
  }
};
