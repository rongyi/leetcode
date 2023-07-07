// https://leetcode.com/problems/maximum-strength-of-a-group/
#include "xxx.hpp"

class Solution {
public:
  long long maxStrength(vector<int> &nums) {
    int sz = nums.size();
    sort(nums.begin(), nums.end());
    long long ret = 1;
    int cnt = 0;
    for (int i = 0; i < sz; i++) {
      // if current number is negative, make sure still have negative number
      if (ret * nums[i] > 0 || (i + 1 < sz && nums[i + 1] < 0)) {
        ret *= nums[i];
        cnt++;
      }
    }
    if (cnt) {
      return ret;
    }

    return nums.back();
  }
};
