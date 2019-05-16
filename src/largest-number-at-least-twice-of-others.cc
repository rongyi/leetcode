// http://leetcode.com/problems/largest-number-at-least-twice-of-others/description/
#include "xxx.h"

class Solution {
public:
  int dominantIndex(vector<int> &nums) {
    if (nums.size() == 1) {
      return 0;
    }
    int top1 = numeric_limits<int>::min();
    int second = top1;
    int ret = -1;
    for (int i = 0; i < nums.size(); i++) {
      auto num = nums[i];
      if (num > top1) {
        second = top1;
        top1 = num;
        ret = i;
      } else if (num > second) {
        second = num;
      }
    }

    return second * 2 <= top1 ? ret : -1;
  }
};
