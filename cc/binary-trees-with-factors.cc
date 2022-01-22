// http://leetcode.com/problems/binary-trees-with-factors/description/
#include "xxx.hpp"

class Solution {
public:
  int numFactoredBinaryTrees(vector<int> &A) {
    long ret = 0;
    long mod = pow(10, 9) + 7;
    sort(A.begin(), A.end());
    unordered_map<int, long> dp;
    for (int i = 0; i < A.size(); i++) {
      dp[A[i]] = 1;
      for (int j = 0; j < i; ++j) {
        if (A[i] % A[j] == 0 && dp.count(A[i] / A[j]) == 1) {
          dp[A[i]] = (dp[A[i]] + dp[A[j]] * dp[A[i] / A[j]]) % mod;
        }
      }
    }
    for (auto kv : dp) {
      ret = (ret + kv.second) % mod;
    }
    return ret;
  }
};
