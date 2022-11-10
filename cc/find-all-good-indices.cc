// https://leetcode.com/problems/find-all-good-indices/
#include "xxx.hpp"

class Solution {
public:
  vector<int> goodIndices(vector<int> &nums, int k) {
    int sz = nums.size();
    vector<int> dp_prev(sz, 1);
    vector<int> dp_after(sz, 1);
    vector<int> ret;

    for (int i = 1; i < sz; ++i) {
      // after number must be smaller or eq
      if (nums[i - 1] >= nums[i]) {
        dp_prev[i] = dp_prev[i - 1] + 1;
      }
    }
    for (int i = sz - 2; i >= 0; --i) {
      // after number must be bigger or eq
      if (nums[i] <= nums[i + 1]) {
        dp_after[i] = dp_after[i + 1] + 1;
      }
    }
    for (int i = k; i < sz - k; ++i) {
      if (dp_prev[i - 1] >= k && dp_after[i + 1] >= k) {
        ret.push_back(i);
      }
    }

    return ret;
  }
};
