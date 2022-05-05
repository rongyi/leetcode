// https://leetcode.com/problems/calculate-digit-sum-of-a-string/
#include "xxx.hpp"

class Solution {
public:
  string digitSum(string s, int k) {
    if (s.size() <= k) {
      return s;
    }
    string next_level{};
    int sz = s.size();
    vector<int> prefix_sum(s.size() + 1, 0);
    for (int i = 0; i < sz; ++i) {
      prefix_sum[i + 1] = prefix_sum[i] + (s[i] - '0');
    }
    for (int i = 0; i < sz; i += k) {
      int cur =
          // prefix_sum[min(i + k - 1 + 1, sz - 1 + 1)] - prefix_sum[i - 1 + 1];
          prefix_sum[min(i + k, sz)] - prefix_sum[i];

      next_level += to_string(cur);
    }

    return digitSum(next_level, k);
  }
};
