// http://leetcode.com/problems/single-threaded-cpu/description/
#include "xxx.h"

class Solution {
public:
  vector<int> getOrder(vector<vector<int>> &tasks) {
    const int n = tasks.size();
    // 加上编号
    // tasks[i] ==> [enquetime, duration, index]
    // 题目说的先按照最短的处理时间来排，如果一样先来先得也就是index
    for (int i = 0; i < n; ++i) {
      tasks[i].push_back(i);
    }
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    // 先按时间先后来排
    sort(tasks.begin(), tasks.end(),
         [](auto &l, auto &r) { return l[0] < r[0]; });
    vector<int> ret;

    long cpu_end = 0;
    int i = 0;
    while (i < n || !pq.empty()) {
      // 这里来保证pq总会有的
      if (pq.empty()) {
        cpu_end = max(cpu_end, (long)tasks[i][0]);
      }
      while (i < n && tasks[i][0] <= cpu_end) {
        pq.push({tasks[i][1], tasks[i][2]});
        i++;
      }
      auto [duration, idx] = pq.top();
      pq.pop();

      cpu_end += duration;
      ret.push_back(idx);
    }

    return ret;
  }
};
