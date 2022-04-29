// https://leetcode.com/problems/find-triangular-sum-of-an-array/
#include "xxx.hpp"

class Solution {
public:
  int triangularSum(vector<int> &nums) {
    return evolution(nums);
  }

private:
  int evolution(vector<int> &nums) {
    if (nums.size() == 1) {
      return nums[0];
    }

    vector<int> next_layer;
    for (int i = 1; i < nums.size(); ++i) {
      next_layer.push_back((nums[i - 1] + nums[i]) % 10);
    }

    return evolution(next_layer);
  }
};
