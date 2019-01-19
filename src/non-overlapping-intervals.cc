// http://leetcode.com/problems/non-overlapping-intervals/description/
#include "xxx.h"

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
  int eraseOverlapIntervals(vector<Interval> &intervals) {
    auto cmp = [](const Interval &l, const Interval &r) -> bool {
      return l.start < r.start;
    };
    sort(intervals.begin(), intervals.end(), cmp);

    int ret = 0;
    int prev = 0;
    for (int i = 1; i < intervals.size(); ++i) {
      // 啊， 落到前面区间里去了
      if (intervals[i].start < intervals[prev].end) {
        ret++;
        // 拿掉横跨最靠前的那个罩子，此时prev指向当前
        if (intervals[i].end < intervals[prev].end) {
          prev = i;
        }
        // 拿掉横跨最靠前的罩子，即删除的是当前的这个，所以prev没变，这里没有行为
      } else {
        prev = i;
      }
    }


    return ret;
  }
};
