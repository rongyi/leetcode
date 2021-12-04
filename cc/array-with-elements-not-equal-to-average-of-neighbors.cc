// https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/
#include "xxx.h"
class Solution {
public:
  vector<int> rearrangeArray(vector<int> &nums) {
    int sz = nums.size();
    sort(nums.begin(), nums.end());

    vector<int> ret;
    for (int i = 0; i < sz / 2; i++) {
      // one small, one big
      ret.push_back(nums[i]);
      ret.push_back(nums[sz - i - 1]);
    }
    if (sz & 1) {
      ret.push_back(nums[sz / 2]);
    }

    return ret;
  }
};
