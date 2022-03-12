// https://leetcode.com/problems/count-the-hidden-sequences/
#include "xxx.hpp"

class Solution {
public:
  int numberOfArrays(vector<int> &differences, int lower, int upper) {
    // take each number as a shift, we see the final pos
    // by those two shift
    using ll = long long;
    ll left_shift = 0;
    ll right_shift = 0;
    ll cur = 0;
    for (auto &d : differences) {
      cur += d;
      left_shift = min(left_shift, cur);
      right_shift = max(right_shift, cur);
    }
    int valid_range = 0;
    for (ll start = lower; start <= upper; ++start) {
      if (start + left_shift < lower || start + right_shift > upper) {
        continue;
      }
      valid_range += 1;
    }

    return valid_range;
  }
};
