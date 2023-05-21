// https://leetcode.com/problems/count-increasing-quadruplets/
#include "xxx.hpp"

class Solution {
public:
  long long countQuadruplets(vector<int> &nums) {
    int sz = nums.size();
    // dp[i] means the valid pair for i < j < k (nums[i] < nums[k] < nums[j])
    // j is the bigger one
    vector<long long> dp(sz, 0ll);
    long long ret = 0;
    for (int i = 0; i < sz; i++) {
      long long petentialask = 0;
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) {
          // 1. so i as l
          ret += dp[j];
          // 2. i can also be petentialk
          petentialask++;
        } else if (nums[i] < nums[j]) {
          // the middle j is the bigger one, so
          // the dp method
          dp[j] += petentialask;
        }
      }
    }
    return ret;
  }
};
