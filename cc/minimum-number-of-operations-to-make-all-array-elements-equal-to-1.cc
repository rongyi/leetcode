// https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/
#include "xxx.hpp"

class Solution {
public:
  int minOperations(vector<int> &nums) {
    // short path
    int sz = nums.size();
    int one_cnt = count(nums.begin(), nums.end(), 1);
    // ok, easy way
    if (one_cnt != 0) {
      return sz - one_cnt;
    }
    // :( hard way
    int ret = numeric_limits<int>::max();
    for (int i = 0; i < sz; i++) {
      int cur = nums[i];
      for (int j = i + 1; j < sz; j++) {
        cur = __gcd(nums[j], cur);
        if (cur == 1) {
          ret = min(ret, (j - i) + (sz - 1));
        }
      }
    }
    if (ret == numeric_limits<int>::max()) {
      return -1;
    }
    return ret;
  }
};
