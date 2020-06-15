// http://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/description/
#include "xxx.h"

class Solution {
public:
  int maxEvents(vector<vector<int>> &events) {
    sort(events.begin(), events.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    int i = 0;
    int ret = 0;
    int d = 0;
    const int n = events.size();

    // d标记的今天
    // pq里存的是结束的时间
    while (pq.size() > 0 || i < n) {
      if (pq.size() == 0) {
        d = events[i][0];
      }
      // 只要开始时间不超过今天，那就由机会去参加
      while (i < n && events[i][0] <= d) {
        pq.push(events[i++][1]);
      }
      // 参加的那个是结束时间最早的那个
      pq.pop();
      ++ret;
      ++d;
      // 如果结束时间已经比d小那么明天就没有机会去参加了
      while (pq.size() > 0 && pq.top() < d) {
        pq.pop();
      }
    }

    return ret;
  }
};
