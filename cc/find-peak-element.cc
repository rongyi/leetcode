// http://leetcode.com/problems/find-peak-element/description/
#include "xxx.h"

class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    // 看成是一个递增序列，如果出现下坡，则前面这个是最大值
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] < nums[i - 1]) {
        return i - 1;
      }
    }
    return nums.size() - 1;
  }
};
