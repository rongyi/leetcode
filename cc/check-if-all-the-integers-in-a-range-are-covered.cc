#include "xxx.hpp"

class Solution {
public:
  bool isCovered(vector<vector<int>> &ranges, int left, int right) {
    sort(ranges.begin(), ranges.end());

    for (auto &r : ranges) {
      // totally contained in this range
      if (r[0] <= left && r[1] >= right) {
        return true;
      }
      // then we shrink the range
      // will never match
      // the left part will never catch, cause the next range starting point
      // is >= current
      if (left < r[0]) {
        return false;
      }
      // shrink the range
      if (left <= r[1]) {
        left = r[1] + 1;
      }
    }

    return left > right;
  }
};
