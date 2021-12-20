// https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/
#include "xxx.h"

class Solution {
public:
  long long interchangeableRectangles(vector<vector<int>> &rectangles) {
    // will overflow for int
    map<double, long long> count;
    for (auto &r : rectangles) {
      // record the same ratio and use m * (m - 1) / 2
      // to get the result
      ++count[r[0] / (double)r[1]];
    }
    long long ret = 0;
    for (auto &kv : count) {
      ret += kv.second * (kv.second - 1) / 2;
    }

    return ret;
  }
};
