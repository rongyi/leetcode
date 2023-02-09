// http://leetcode.com/problems/search-in-rotated-sorted-array/description/
#include "xxx.hpp"
class Solution {
public:
  int search(vector<int> &nums, int target) {
    // 45678123
    // 81234567
    // 12345678
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r) {
      auto mid = l + (r - l) / 2;
      if (nums[mid] == target) {
        return mid;
      }
      if (nums[mid] > nums[r]) {
        if (target >= nums[l] && target < nums[mid]) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      } else if (nums[mid] < nums[l]) {
        if (target > nums[mid] && target <= nums[r]) {
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      } else {
        if (target < nums[mid]) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
    }

    return -1;
  }
};

