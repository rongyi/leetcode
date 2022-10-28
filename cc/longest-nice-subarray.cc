// https://leetcode.com/problems/longest-nice-subarray/
#include "xxx.hpp"

class Solution {
public:
  int longestNiceSubarray(vector<int> &nums) {
    int sz = nums.size();
    int ret = 1;
    for (int i = 0; i < sz; i++) {
      int j = i + 1;
      int cur = nums[i];
      for (; j < sz; ++j) {
        // yes can combine
        if ((cur & nums[j]) == 0) {
          cur |= nums[j];
        } else {
          break;
        }
      }

      ret = max(ret, j - i);
    }

    return ret;
  }
};
