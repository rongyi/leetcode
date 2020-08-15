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

    while (pq.size() > 0 || i < n) {
      if (pq.size() == 0) {
        // 下一轮的第一个元素
        d = events[i][0];
      }
      // 把所有的开始日期符合条件的都拉进来
      while (i < n && events[i][0] <= d) {
        pq.push(events[i++][1]);
      }
      pq.pop();
      d++;
      ret++;
      // 明天的时间来算，这些都已经过期了，参加不了
      while (!pq.empty() && pq.top() < d) {
        pq.pop();
      }
    }

    return ret;
  }
};
