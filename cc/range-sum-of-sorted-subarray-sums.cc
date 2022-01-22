// http://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/
#include "xxx.hpp"

class Solution {
public:
  // naive method
  int rangeSum(vector<int> &nums, int n, int left, int right) {
    vector<int> sums;
    const int mod = pow(10, 9) + 7;
    for (int i = 0; i < nums.size(); ++i) {
      int sum = 0;
      for (int j = i; j < nums.size(); ++j) {
        sum += nums[j];
        sums.push_back(sum % mod);
      }
    }
    sort(sums.begin(), sums.end());
    int ret = 0;
    for (int i = left - 1; i < right; ++i) {
      ret = (ret + sums[i]) % mod;
    }

    return ret;
  }
};
