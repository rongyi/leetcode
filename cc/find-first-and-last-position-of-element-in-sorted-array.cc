// http://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
#include "xxx.hpp"
class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int l = mylb(nums, target);
    // [2, 2, 2, 3]
    //           ^
    int u = mylb(nums, target + 1) - 1;
    if (l < nums.size() && nums[l] == target) {
      return {l, u};
    }
    return {-1, -1};
  }

private:
  int mylb(vector<int> &nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r) {
      auto mid = l + (r - l) / 2;
      if (target > nums[mid]) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    return l;
  }
};
