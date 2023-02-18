// http://leetcode.com/problems/insert-interval/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    //         |---|
    // |--| |-|
    //           |-----|
    //                |---|
    int sz = intervals.size();
    int i = 0;
    vector<vector<int>> ret;
    while (i < sz && intervals[i][1] < newInterval[0]) {
      ret.push_back(intervals[i]);
      i++;
    }
    if (i == sz) {
      ret.push_back(newInterval);
      return ret;
    }
    int prev_begin = -1;
    int prev_end = -1;
    if (intervals[i][0] > newInterval[1]) {
      prev_begin = newInterval[0];
      prev_end = newInterval[1];
    } else {
      prev_begin = min(newInterval[0], intervals[i][0]);
      prev_end = max(newInterval[1], intervals[i][1]);
      i++;
    }
    for (; i < sz; i++) {
      if (intervals[i][0] > prev_end) {
        ret.push_back({prev_begin, prev_end});
        prev_begin = intervals[i][0];
        prev_end = intervals[i][1];
      } else {
        prev_end = max(prev_end, intervals[i][1]);
      }
    }
    ret.push_back({prev_begin, prev_end});
    return ret;
  }
};

