// http://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/
#include "xxx.hpp"

class Solution {
public:
  int minPairSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int sz = nums.size();
    int ret = 0;

    for (int i = 0; i < sz / 2; ++i) {
      ret = max(ret, nums[i] + nums[sz - i - 1]);
    }

    return ret;
  }
};
