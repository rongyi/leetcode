// https://leetcode.com/problems/number-of-distinct-roll-sequences/
#include "xxx.hpp"

class Solution {
public:
  int distinctSequences(int n, int prev = 0, int pprev = 0) {
    // base case
    if (n == 0) {
      return 1;
    }

    if (dp_[n][prev][pprev] == 0) {
      for (int d = 1; d < 7; ++d) {
        if (d != prev && d != pprev && (prev == 0 || gcd(d, prev) == 1)) {
          dp_[n][prev][pprev] =
              (dp_[n][prev][pprev] + distinctSequences(n - 1, d, prev)) %
              1000000007;
        }
      }
    }

    return dp_[n][prev][pprev];
  }

private:
  int dp_[10001][7][7] = {};
};

