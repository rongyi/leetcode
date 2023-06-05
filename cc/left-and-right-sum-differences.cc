// https://leetcode.com/problems/left-and-right-sum-differences/
#include "xxx.hpp"

class Solution {
public:
  vector<int> leftRightDifference(vector<int> &nums) {
    int sz = nums.size();
    vector<int> lsum(sz, 0);
    vector<int> rsum(sz, 0);
    for (int i = 1; i < sz; i++) {
      lsum[i] = lsum[i - 1] + nums[i - 1];
    }

    for (int i = sz - 2; i >= 0; i--) {
      rsum[i] = rsum[i + 1] + nums[i + 1];
    }

    vector<int> ret(sz, 0);

    for (int i = 0; i < sz; i++) {
      ret[i] = abs(lsum[i] - rsum[i]);
    }

    return ret;
  }
};
