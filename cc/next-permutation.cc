// http://leetcode.com/problems/next-permutation/description/
#include "xxx.hpp"
class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    next_permutation(nums, 0, nums.size());
  }

private:
  bool next_permutation(vector<int> &nums, int begin, int end) {
    // from right to left find the first digit which violates the increase trend
    int p = end - 2;
    while (p > -1 && nums[p] >= nums[p + 1])
      --p;

    if (p == -1) {
      reverse(&nums[begin], &nums[end]);
      return false;
    }

    int c = end - 1;
    while (c > 0 && nums[c] <= nums[p])
      --c;

    swap(nums[p], nums[c]);
    reverse(&nums[p + 1], &nums[end]);
    return true;
  }
};
