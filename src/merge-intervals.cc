// http://leetcode.com/problems/merge-intervals/description/
#include "one.h"

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
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
      cout << "prev end" << prev.end << endl;
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

int main() {
  Solution so;
  vector<Interval> input{Interval(1, 4), Interval(0, 2), Interval(3, 5)};
  auto ret = so.merge(input);
  for (auto &itv : ret) {
    cout << itv.start << " --> " << itv.end << endl;
  }

}
