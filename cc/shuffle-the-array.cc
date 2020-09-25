// http://leetcode.com/problems/shuffle-the-array/description/
#include "xxx.h"

class Solution {
public:
  vector<int> shuffle(vector<int> &nums, int n) {
    vector<int> ret(nums.size(), 0);

    for (int i = 0, cur = 0; i < n; ++i) {
      ret[cur++] = nums[i];
      ret[cur++] = nums[n + i];
    }

    return ret;
  }
};
