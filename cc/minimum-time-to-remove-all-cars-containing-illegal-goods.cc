// https://leetcode.com/problems/minimum-time-to-remove-all-cars-containing-illegal-goods/
#include "xxx.hpp"

class Solution {
public:
  int minimumTime(string s) {
    int sz = s.size();
    vector<int> left(sz, 0);
    vector<int> right(sz, 0);
    if (s[0] == '1') {
      left[0] = 1;
    }
    for (int i = 1; i < sz; ++i) {
      if (s[i] == '1') {
        // remove from the middle,
        // (the middle case is relayed by zero case to i - 1)
        // or just remove from the begin to this pos which cost is (i + 1)
        left[i] = min(left[i - 1] + 2, i + 1);
      } else {
        left[i] = left[i - 1];
      }
    }

    if (s[sz - 1] == '1') {
      right[sz - 1] = 1;
    }
    for (int i = sz - 2; i >= 0; --i) {
      if (s[i] == '1') {
        // same as left
        right[i] = min(right[i + 1] + 2, sz - i);
      } else {
        right[i] = right[i + 1];
      }
    }
    // 1. clean from the left to the end
    // 2. clean from the right to the begin
    int ret = min(left[sz - 1], right[0]);
    // the case in between
    // clean from left to i, and clean the rest from right
    for (int i = 0; i <= sz - 2; ++i) {
      ret = min(ret, left[i] + right[i + 1]);
    }
    return ret;
  }
};
