// http://leetcode.com/problems/falling-squares/description/
#include "xxx.h"

class Solution {
private:
  struct Interval {
    int start_;
    int end_;
    int height_;
    Interval(int start, int end, int height) {
      start_ = start;
      end_ = end;
      height_ = height;
    }
  };

public:
  vector<int> fallingSquares(vector<vector<int>> &positions) {
    vector<int> ret;
    vector<Interval> intervals;

    int h = 0;
    for (auto &p : positions) {
      Interval cur(p[0], p[0] + p[1] - 1, p[1]);
      h = max(h, getHeight(intervals, cur));
      ret.push_back(h);
    }

    return ret;
  }

private:
  int getHeight(vector<Interval> &intervals, Interval &cur) {
    int prev_height = 0;
    for (auto &itv : intervals) {
      // 不搭嘎
      if (itv.end_ < cur.start_) {
        continue;
      }
      if (itv.start_ > cur.end_) {
        continue;
      }
      prev_height = max(prev_height, itv.height_);
    }
    cur.height_ += prev_height;
    intervals.push_back(cur);

    return cur.height_;
  }
};
