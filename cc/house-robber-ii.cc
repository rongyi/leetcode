// http://leetcode.com/problems/house-robber-ii/description/
#include "xxx.hpp"

class Solution {
public:
  int rob(vector<int> &nums) {
    int sz = nums.size();
    if (sz <= 1) {
      return nums[0];
    }
    // split to two problems:
    // 1. for 0..sz-1
    vector<int> dp1(sz, 0);
    // 2. for 1..sz
    vector<int> dp2(sz, 0);

    dp1[1] = nums[0];
    // dp value put to i+1
    for (int i = 1; i < sz - 1; i++) {
      // take or not take current
      dp1[i + 1] = max(dp1[i], nums[i] + dp1[i - 1 /* + 1 - 2*/]);
    }

    // dp value put to i
    dp2[1] = nums[1];
    for (int i = 2; i < sz; i++) {
      dp2[i] = max(dp2[i - 2] + nums[i], dp2[i - 1]);
    }

    return max(dp1[sz - 1], dp2[sz - 1]);
  }
};
