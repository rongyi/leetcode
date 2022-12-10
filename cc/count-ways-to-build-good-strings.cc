// https://leetcode.com/problems/count-ways-to-build-good-strings/
#include "xxx.hpp"

class Solution {
public:
  int countGoodStrings(int low, int high, int zero, int one) {
    long long ret = 0;

    vector<long long> dp(high + 1, -1);
    for (int i = low; i <= high; ++i) {
      ret = (ret + recur(i, zero, one, dp)) % mod_;
    }

    return ret;
  }

private:
  int recur(int target, int zero, int one, vector<long long> &dp) {
    // can be formed
    if (target == 0) {
      return 1;
    }
    if (target < 0) {
      return 0;
    }
    if (dp[target] != -1) {
      return dp[target];
    }

    dp[target] = (recur(target - zero, zero, one, dp) +
                  recur(target - one, zero, one, dp)) %
                 mod_;

    return dp[target];
  }

private:
  int mod_ = 1e9 + 7;
  map<string, long long> cnt;
};
