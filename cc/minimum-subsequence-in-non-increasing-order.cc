// http://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/description/
#include "xxx.h"

class Solution {
public:
  vector<int> minSubsequence(vector<int> &nums) {
    auto sum = accumulate(nums.begin(), nums.end(), 0);
    vector<int> ret;
    sort(nums.begin(), nums.end());
    int cur_sum = 0;
    for (int i = nums.size() - 1; i >= 0; --i) {
      if (cur_sum <= sum / 2) {
        cur_sum += nums[i];
        ret.push_back(nums[i]);
        continue;
      }

      break;
    }

    sort(ret.begin(), ret.end(), std::greater<>());
    return ret;
  }
};
