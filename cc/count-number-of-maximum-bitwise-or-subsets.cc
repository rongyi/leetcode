// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/
#include "xxx.hpp"

class Solution {
public:
  int countMaxOrSubsets(vector<int> &nums) {
    int maxor = 0;
    for (auto num: nums) {
      maxor |= num;
    }
    int sz = nums.size();
    int total = 0;
    // just using the mask, you think too much
    for (int mask = 0; mask < (1 << sz); ++mask) {
      int curor = 0;;
      for (int i = 0; i < sz; ++i) {
        if ((mask >> i) & 1) {
          curor |= nums[i];
        }
      }
      if (curor == maxor) {
        total++;
      }
    }
    return total;
  }
};
