// http://leetcode.com/problems/3sum-with-multiplicity/description/
#include "xxx.h"

class Solution {
public:
  int threeSumMulti(vector<int> &A, int target) {
    const int mod = pow(10, 9) + 7;
    // 先缓存 i + j
    // dp[i][j] ==> 表示index终止到i和为j的个数
    const int n = A.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        auto sum = A[i] + A[j];
        if (sum <= target) {
          ++dp[j][sum];
        }
      }
    }
    int ret = 0;

    for (int k = 2; k < n; k++) {
      if (A[k] <= target) {
        for (int j = 0; j < k; j++) {
          ret = (ret + dp[j][target - A[k]]) % mod;
        }
      }
    }
    return ret;
  }
};
