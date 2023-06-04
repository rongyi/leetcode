// https://leetcode.com/problems/minimum-score-by-changing-two-elements/
#include "xxx.hpp"

// shitty problem
class Solution {
public:
  int minimizeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    // 1. delete two small
    // 2. delete two big
    // 3. delete one small, one big
    int sz = nums.size();
    int op1 = nums.back() - nums[2];
    int op2 = nums[sz - 3] - nums[0];
    int op3 = nums[sz - 2] - nums[1];

    return min({op1, op2, op3});
  }
};
