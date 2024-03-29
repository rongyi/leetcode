// http://leetcode.com/problems/find-peak-element/description/
#include "xxx.hpp"

class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    int l = 0;
    int r = nums.size() - 1;
    while (l < r) {
      auto mid = l + (r - l) / 2;
      if (nums[mid] < nums[mid + 1]) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }

    return l;
  }
};
