// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/
#include "xxx.hpp"

class Solution {
public:
  int minimizeMax(vector<int> &nums, int p) {
    int sz = nums.size();
    sort(nums.begin(), nums.end());
    int l = 0;
    int r = nums[sz - 1] - nums[0];

    while (l < r) {
      auto mid = l + (r - l) / 2;
      int valid_pairs = 0;

      for (int i = 1; i < sz; i++) {
        // we collect
        if (nums[i] - nums[i - 1] <= mid) {
          valid_pairs++;
          ++i;
        }
      }

      // too loose, strict condition
      if (valid_pairs >= p) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }

    return l;
  }
};
