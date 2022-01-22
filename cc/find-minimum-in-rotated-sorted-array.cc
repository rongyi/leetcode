// http://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
#include "xxx.hpp"

class Solution {
public:
  // we prefer the recursive version
  int findMin(vector<int> &nums) { return dofind(nums, 0, nums.size() - 1); }

private:
  int dofind(vector<int> &nums, int left, int right) {
    if (right == left) {
      return nums[left];
    }
    if (right == left + 1) {
      return min(nums[left], nums[right]);
    }
    int mid = left + (right - left) / 2;
    if (nums[right] > nums[left]) {
      return nums[left];
    } else if (nums[right] == nums[left]) {
      return dofind(nums, left + 1, right);
    } else if (nums[mid] >= nums[left]) {
      return dofind(nums, mid, right);
    }
    return dofind(nums, left, mid);
  }
};
