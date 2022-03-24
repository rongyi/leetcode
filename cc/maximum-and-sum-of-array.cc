// https://leetcode.com/problems/maximum-and-sum-of-array/
#include "xxx.hpp"

class Solution {
public:
  int maximumANDSum(vector<int> &nums, int numSlots) {
    nums.resize(numSlots * 2);
    int sz = nums.size();
    vector<int> dp(1 << sz, 0);
    for (int m = 1; m < (1 << sz); ++m) {
      // int bit_cnt = __builtin_popcount(m);
      int bit_cnt = bitcount(m);
      int last_slot = (bit_cnt + 1) / 2;
      for (int i = 0; i < sz; ++i) {
        if ((m >> i) & 1) {
          // transition from m ^ ( 1 << i ) --> m
          // e.g. 10100 -> 10101
          dp[m] = max(dp[m], dp[m ^ (1 << i)] + (last_slot & nums[i]));
        }
      }
    }

    return dp[(1 << sz) - 1];
  }

private:
  int bitcount(int n) {
    int ret = 0;
    while (n) {
      ++ret;
      n &= (n - 1);
    }

    return ret;
  }
};
