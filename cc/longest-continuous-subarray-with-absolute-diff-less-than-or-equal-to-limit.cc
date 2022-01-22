// http://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/
#include "xxx.hpp"

class Solution {
public:
  int longestSubarray(vector<int> &nums, int limit) {
    // how to get max/min of a range? ==> multiset
    multiset<int> sorted;
    int j = 0;
    int ret = 1;

    for (int i = 0; i < nums.size(); ++i) {
      sorted.insert(nums[i]);
      while (*sorted.rbegin() - *sorted.begin() > limit) {
        sorted.erase(sorted.find(nums[j++]));
      }
      ret = max(ret, i - j + 1);
    }

    return ret;
  }
};
