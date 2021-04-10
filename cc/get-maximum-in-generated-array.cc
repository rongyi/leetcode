// http://leetcode.com/problems/get-maximum-in-generated-array/description/
#include "xxx.h"

class Solution {
public:
  int getMaximumGenerated(int n) {
    if (n < 1) {
      return 0;
    }
    vector<int> nums(n + 1, 0);
    nums[1] = 1;
    for (int i = 2; i < n + 1; ++i) {
      if (i & 1) {
        nums[i] = nums[i / 2] + nums[i / 2 + 1];
      } else {
        nums[i] = nums[i / 2];
      }
    }

    return *max_element(nums.begin(), nums.end());
  }
};
