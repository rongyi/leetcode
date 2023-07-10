// https://leetcode.com/problems/neither-minimum-nor-maximum/
#include "xxx.hpp"

class Solution {
public:
  int findNonMinOrMax(vector<int> &nums) {
    int sz = nums.size();
    if (sz <= 2) {
      return -1;
    }
    int max_num = numeric_limits<int>::min();
    int min_num = numeric_limits<int>::max();
    for (int i = 0; i < sz; i++) {
      max_num = max(max_num, nums[i]);
      min_num = min(min_num, nums[i]);
    }
    for (auto &num : nums) {
      if (num != max_num && num != min_num) {
        return num;
      }
    }
    return -1;
  }
};
