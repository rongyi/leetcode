// http://leetcode.com/problems/unique-binary-search-trees/description/
#include "xxx.hpp"
class Solution {
public:
  int numTrees(int n) {
    // f(n) n nodes total bsts
    // f(n) = g(1, n) + ... + g(n, n)
    // g(i, n)
    // 1 2 3 4 5
    //       ^
    // 3 * 1
    // f(n) =  f(i - 1) * f(n - i) sum from 1..=n
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        dp[i] += dp[j - 1] * dp[i - j];
      }
    }
    return dp[n];
  }
};
