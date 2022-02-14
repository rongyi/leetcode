// https://leetcode.com/problems/removing-minimum-and-maximum-from-array/
#include "xxx.hpp"

class Solution {
public:
  // delete the biggest and smallest one
  int minimumDeletions(vector<int> &nums) {
    int min_num = numeric_limits<int>::max();
    int max_num = numeric_limits<int>::min();
    int min_idx = -1;
    int max_idx = -1;
    int sz = nums.size();
    for (int i = 0; i < sz; ++i) {
      auto &cur = nums[i];
      if (cur > max_num) {
        max_num = cur;
        max_idx = i;
      }
      if (cur < min_num) {
        min_num = cur;
        min_idx = i;
      }
    }
    auto l = min(min_idx, max_idx);
    auto r = max(min_idx, max_idx);
    if (l == r) {
      // from left, or right
      return min(l + 1, sz - l);
    }
    // either all from left, or all from right or just from front and tail of
    // each other
    return min({r + 1, sz - l, l + 1 + sz - r});
  }
};
