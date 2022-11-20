// https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/
#include "xxx.hpp"

class Solution {
public:
  int subarrayGCD(vector<int> &nums, int k) {
    int sz = nums.size();
    int ret = 0;
    for (int i = 0; i < sz; ++i) {
      for (int j = i; j < sz && nums[j] % k == 0; ++j) {
        nums[i] = gcd(nums[i], nums[j]);
        ret += (nums[i] == k);
      }
    }
    return ret;
  }
};
