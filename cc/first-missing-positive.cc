// http://leetcode.com/problems/first-missing-positive/description/
#include "xxx.hpp"

class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    // 0 1 2 3 4
    // 1 2 3 4 5
    // i nums[i]
    // i + 1 = nums[i]
    // i = nums[i] - 1
    // nums[i] = nums[nums[i] - 1]
    // 0 1 2 3 4
    // 5 1 3 4 2
    // 2 1 3 4 5
    // 1 2 3 4 5 sz + 1
    // nums[i] != i + 1
    int sz = nums.size();
    for (int i = 0; i < sz; i++) {
      while (nums[i] > 0 && nums[i] <= sz && nums[nums[i] - 1] != nums[i]) {
        swap(nums[i], nums[nums[i] - 1]);
      }
    }
    for (int i = 0; i < sz; i++) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }
    return sz + 1;
  }
};
