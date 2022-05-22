// https://leetcode.com/problems/number-of-ways-to-split-array/
#include "xxx.hpp"

class Solution {
public:
  int waysToSplitArray(vector<int> &nums) {
    int sz = nums.size();
    vector<long long> prefix_sum(sz + 1, 0);
    vector<long long> suffix_sum(sz + 1, 0);
    for (int i = 0; i < sz; ++i) {
      prefix_sum[i + 1] = prefix_sum[i] + nums[i];
    }
    for (int i = sz - 1; i >= 0; --i) {
      suffix_sum[i] = suffix_sum[i + 1] + nums[i];
    }

    int cnt = 0;
    for (int i = 0; i < sz - 1; ++i) {
      auto lsum = prefix_sum[i + 1];
      auto rsum = suffix_sum[i + 1];
      if (lsum >= rsum) {
        cnt++;
      }
    }

    return cnt;
  }
};
