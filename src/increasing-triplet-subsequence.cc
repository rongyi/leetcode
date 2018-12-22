// http://leetcode.com/problems/increasing-triplet-subsequence/description/
#include "xxx.h"

class Solution {
public:
  bool increasingTriplet(vector<int> &nums) {
    const int n = nums.size();
    if (n < 3) {
      return false;
    }
    // 缓存两个小的，如果再遇到比这两个大的那就有三个了。
    int small1 = numeric_limits<int>::max();
    int small2 = numeric_limits<int>::max();
    for (auto i : nums) {
      if (i <= small1) {
        small1 = i;
      } else if (i <= small2) {
        small2 = i;
      } else {
        return true;
      }
    }

    return false;
  }
};
