// https://leetcode.com/problems/describe-the-painting/
#include "xxx.h"

class Solution {
public:
  // https://leetcode.com/problems/describe-the-painting/discuss/1359717/Python-Easy-solution-in-O(n*logn)-with-detailed-explanation
  vector<vector<long long>> splitPainting(vector<vector<int>> &segments) {
    map<int, long long> check_points;
    for (auto &seg : segments) {
      // each [start, end) is check point
      // meet a new point: add
      // leaving a point: minus
      check_points[seg[0]] += seg[2];
      check_points[seg[1]] -= seg[2];
    }
    vector<vector<long long>> ret;
    long long prev = -1;
    // real color >= 1
    long long cur_color = 0;
    for (auto &kv : check_points) {
      if (prev != -1 && cur_color != 0) {
        ret.push_back({prev, kv.first, cur_color});
      }
      // mix the color
      cur_color += kv.second;
      prev = kv.first;
    }

    return ret;
  }
};
