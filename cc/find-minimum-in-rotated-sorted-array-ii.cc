// http://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
#include "xxx.hpp"

class Solution {
public:
  int findMin(vector<int> &nums) {
    int l = 0;
    int r = nums.size() - 1;
    while (l < r) {
      auto mid = l + (r - l) / 2;
      if (nums[mid] > nums[r]) {
        l = mid + 1;
      } else if (nums[mid] < nums[r]) {
        r = mid;
      } else {
        r--;
      }
    }
    return nums[l];
  }
};
