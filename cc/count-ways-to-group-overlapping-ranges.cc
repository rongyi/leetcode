// https://leetcode.com/problems/count-ways-to-group-overlapping-ranges/
#include "xxx.hpp"

class Solution {
public:
  int countWays(vector<vector<int>> &ranges) {
    int sz = ranges.size();
    sort(ranges.begin(), ranges.end());
    long long ret = 2;
    int group = 1;
    int prev_end = ranges[0][1];
    int mod = 1e9 + 7;

    for (int i = 1; i < sz; i++) {
      // oops, merged!
      if (ranges[i][0] <= prev_end) {
        prev_end = max(prev_end, ranges[i][1]);
      } else {
        // another group
        group += 1;
        // for next round
        prev_end = ranges[i][1];
        // we  cound just do (1 << group)
        // but we may overflow, so we did it step by step
        ret = (ret * 2) % mod;
      }
    }

    return ret;
  }
};
