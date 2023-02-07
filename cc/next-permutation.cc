// http://leetcode.com/problems/next-permutation/description/
#include "xxx.hpp"
class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int sz = nums.size();
    int j = sz - 2;
    for (; j >= 0; --j) {
      if (nums[j] < nums[j + 1]) {
        break;
      }
    }
    if (j < 0) {
      // 3 2 1
      reverse(nums.begin(), nums.end());
      return;
    }
    int i = sz - 1;
    for (; i > j; --i) {
      if (nums[i] > nums[j]) {
        break;
      }
    }
    swap(nums[i], nums[j]);
    reverse(nums.begin() + j + 1, nums.end());
  }
};
