// https://leetcode.com/problems/count-the-number-of-fair-pairs/
#include "xxx.hpp"

class Solution {
public:
  long long countFairPairs(vector<int> &nums, int lower, int upper) {
    sort(nums.begin(), nums.end());
    auto countless = [&](int val) -> long long {
      int sz = nums.size();
      long long ret = 0;
      int l = 0;
      int r = sz - 1;
      while (l < r) {
        long long cur_sum = 0ll + nums[l] + nums[r];
        if (cur_sum > val) {
          r -= 1;
        } else {
          ret += (r - l);
          l += 1;
        }
      }

      return ret;
    };

    return countless(upper) - countless(lower - 1);
  }
};
