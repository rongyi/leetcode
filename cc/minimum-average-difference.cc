// https://leetcode.com/problems/minimum-average-difference/
#include "xxx.hpp"

class Solution {
public:
  int minimumAverageDifference(vector<int> &nums) {
    int sz = nums.size();
    vector<long long> prefix(sz + 1, 0);
    vector<long long> suffix(sz + 1, 0);

    for (int i = 0; i < sz; ++i) {
      prefix[i + 1] = prefix[i] + nums[i];
    }
    for (int i = sz - 1; i >= 0; --i) {
      suffix[i] = suffix[i + 1] + nums[i];
    }
    int min_idx = sz - 1;
    long long min_value = prefix[sz] / sz;

    for (int i = sz - 2; i >= 0; --i) {
      long long avg_suf = suffix[i + 1] / (sz - i - 1);
      long long avg_pre = prefix[i + 1] / (i + 1);
      long long cur_value = abs(avg_pre - avg_suf);
      if (cur_value <= min_value) {
        min_idx = i;
        min_value = cur_value;
      }
    }

    return min_idx;
  }
};
