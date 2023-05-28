// https://leetcode.com/problems/count-the-number-of-fair-pairs/
#include "xxx.hpp"

class Solution {
public:
  long long countFairPairs(vector<int> &nums, int lower, int upper) {
    sort(nums.begin(), nums.end());
    auto countless = [&](int val) -> long long {
      int sz = nums.size();
      long long ret = 0;
      for (int i = 0, j = sz - 1; i < j; i++) {
        while (i < j && nums[i] + nums[j] > val) {
          j--;
        }
        ret += j - i;
      }

      return ret;
    };

    return countless(upper) - countless(lower - 1);
  }
};
