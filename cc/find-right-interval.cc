// http://leetcode.com/problems/find-right-interval/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> findRightInterval(vector<Interval> &intervals) {
    const int n = intervals.size();
    vector<int> ret;
    map<int, int> cache;

    for (int i = 0; i < n; ++i) {
      cache[intervals[i].start] = i;
    }

    for (auto in : intervals) {
      auto it = cache.lower_bound(in.end);
      if (it == cache.end()) {
        ret.push_back(-1);
      } else {
        ret.push_back(it->second);
      }
    }

    return ret;
  }
};
