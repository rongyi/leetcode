// http://leetcode.com/problems/remove-covered-intervals/description/
#include "xxx.hpp"

class Solution {
public:
  int removeCoveredIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         // ordered by start and then by end
         [](vector<int> &l, vector<int> &r) -> bool {
           if (l[0] == r[0]) {
             return l[1] < r[1];
           }
           return l[0] < r[0];
         });
    int ret = 1;
    int cur_end = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
      // 这个区间被罩住了，跨不过去,因为已经是sort过了，所以start肯定被罩住了
      // 就看end了
      if (intervals[i][1] <= cur_end) {
        continue;
      }
      ++ret;
      cur_end = intervals[i][1];
    }

    return ret;
  }
};
