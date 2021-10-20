// http://leetcode.com/problems/maximum-alternating-subsequence-sum/description/
#include "xxx.h"

class Solution {
public:
  long long maxAlternatingSum(vector<int> &nums) {
    // alternate: even +
    //            odd -
    using ll = long long;
    // 0 end with even index
    // 1 end with odd index
    ll prev[2] = {0, 0};
    for (int i = 0; i < nums.size(); ++i) {
      ll cur[2] = {0, 0};
      // we take or not take current num
      // 1. don't take, cur[0] => prev[0]
      // 2. take cur[0] = prev[1] + nums[i] (prev[1] keep the latest value to
      // num just before)

      // odd case is similar
      cur[0] = max(prev[1] + nums[i], prev[0]);
      cur[1] = max(prev[0] - nums[i], prev[1]);
      swap(prev, cur);
    }

    return prev[0];
  }
};
