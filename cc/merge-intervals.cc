// http://leetcode.com/problems/merge-intervals/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ret;
    int prev_begin = intervals[0][0];
    int prev_end = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i][0] > prev_end) {
        ret.push_back({prev_begin, prev_end});
        prev_begin = intervals[i][0];
        prev_end = intervals[i][1];
      } else {
        // |-----|
        //     |-----|
        // |-----|
        //    |-|
        prev_end = max(prev_end, intervals[i][1]);
      }
    }

    ret.push_back({prev_begin, prev_end});

    return ret;
  }
};
