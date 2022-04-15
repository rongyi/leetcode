// https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/
#include "xxx.hpp"

// shitty problem
// too much core case
class Solution {
public:
  int maximumTop(vector<int> &nums, int k) {
    int sz = nums.size();
    if (k == 0) {
      return sz > 0 ? nums[0] : -1;
    }
    if (k == 1) {
      return sz == 1 ? -1 : nums[1];
    }
    if (sz == 1) {
      return (k % 2 == 0) ? nums[0] : -1;
    }
    int mx = *max_element(nums.begin(), nums.begin() + min(k - 1, sz));
    if (k < sz) {
      mx = max(mx, nums[k]);
    }
    return mx;
  }
};
