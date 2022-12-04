// https://leetcode.com/problems/apply-operations-to-an-array/
#include "xxx.hpp"

class Solution {
public:
  vector<int> applyOperations(vector<int> &nums) {
    int sz = nums.size();
    for (int i = 0; i < sz - 1; ++i) {
      if (nums[i] == nums[i + 1]) {
        nums[i] *= 2;
        nums[i + 1] = 0;
      }
    }
    vector<int> ret(sz, 0);
    for (int i = 0, j = 0; i < sz; ++i) {
      if (nums[i] != 0) {
        ret[j++] = nums[i];
      }
    }
    return ret;
  }
};
