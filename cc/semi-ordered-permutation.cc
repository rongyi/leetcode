// https://leetcode.com/problems/semi-ordered-permutation/
#include "xxx.hpp"

class Solution {
public:
  int semiOrderedPermutation(vector<int> &nums) {
    int sz = nums.size();
    int lidx = -1;
    int ridx = -1;
    for (int i = 0; i < sz; i++) {
      if (nums[i] == 1) {
        lidx = i;
      } else if (nums[i] == sz) {
        ridx = i;
      }
    }

    int ret = lidx + (sz - ridx - 1);
    if (lidx > ridx) {
      ret -= 1;
    }

    return ret;
  }
};
