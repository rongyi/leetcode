// https://leetcode.com/problems/find-the-value-of-the-partition/
#include "xxx.hpp"

class Solution {
public:
  // not subarray, just collect to two bags
  int findValueOfPartition(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int gap = numeric_limits<int>::max();
    for (int i = 1; i < nums.size(); i++) {
      gap = min(gap, nums[i] - nums[i - 1]);
    }

    return gap;
  }
};
