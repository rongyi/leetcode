// https://leetcode.com/problems/number-of-zero-filled-subarrays/
#include "xxx.hpp"

class Solution {
public:
  long long zeroFilledSubarray(vector<int> &nums) {
    long long ret = 0;
    int sz = nums.size();

    for (int i = 0; i < sz;) {
      if (nums[i] == 0) {
        int j = i;
        // may be at the end
        for (; j < sz && nums[j] == 0; ++j)
          ;
        long long len = j - i;
        ret += ((len + 1) * len) / 2;
        i = j;
      } else {
        i++;
      }
    }

    return ret;
  }
};
