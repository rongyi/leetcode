// https://leetcode.com/problems/number-of-unique-good-subsequences/
#include "xxx.hpp"

class Solution {
public:
  int numberOfUniqueGoodSubsequences(string binary) {
    int mod = 1e9 + 7;
    using ll = long long;
    // i, j can be 0, 1, it's not the index,
    // means start char is 0  or 1
    ll dp[2][2] = {};
    for (auto &c : binary) {
      if (c == '0') {
        // we have a single subsequence '0'
        dp[0][0] = 1;
        // we can append 0 th prev subsequence which start is 1
        dp[1][0] = (dp[1][1] + dp[1][0]) % mod;
      } else {
        // other than append 1 to current ,
        // we also need a single '1' whihc is valid
        dp[1][1] = (dp[1][1] + dp[1][0] + 1) % mod;
      }
    }

    return (dp[0][0] + dp[1][1] + dp[1][0]) % mod;
  }
};
