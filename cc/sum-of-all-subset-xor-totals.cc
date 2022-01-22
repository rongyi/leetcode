// http://leetcode.com/problems/sum-of-all-subset-xor-totals/description/
#include "xxx.hpp"

class Solution {
public:
  int subsetXORSum(vector<int> &nums) {
    int sz = nums.size();
    int total = (1 << sz);
    int ret = 0;
    for (int cur = 0; cur < total; ++cur) {
      int sum_cur = 0;
      for (int i = 0; i < sz; ++i) {
        if ((cur & (1 << i)) != 0) {
          sum_cur ^= nums[i];
        }
      }
      ret += sum_cur;
    }
    return ret;
  }
};
