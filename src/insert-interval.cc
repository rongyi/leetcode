// http://leetcode.com/problems/insert-interval/description/
#include "xxx.h"

/**
 * Definition for an interval.
 */

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
  // intervals is already sorted
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    intervals.push_back(newInterval);
    return merge(intervals);
  }

private:
  vector<Interval> merge(vector<Interval> &intervals) {
    const int n = intervals.size();
    if (n <= 1) {
      return intervals;
    }

    sort(intervals.begin(), intervals.end(),
         [](const Interval &left, const Interval &right) -> bool {
           return left.start < right.start;
         });
    vector<Interval> ret;
    ret.push_back(intervals[0]);
    int ret_index = 0;

    for (int i = 1; i < n; ++i) {
      auto prev = ret[ret_index];
      auto cur = intervals[i];
      // no interaction, do nothing
      if (cur.start > prev.end) {
        ret.push_back(cur);
        ret_index++;
      } else {
        Interval newitv(prev.start, max(cur.end, prev.end));
        ret.pop_back();
        ret.push_back(newitv);
      }
    }

    return ret;
  }
};
