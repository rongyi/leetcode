// https://leetcode.com/problems/two-best-non-overlapping-events/
#include "xxx.hpp"

class Solution {
public:
  int maxTwoEvents(vector<vector<int>> &events) {
    int prev_max = 0;
    // by start time
    sort(events.begin(), events.end());
    int ret = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto &e: events) {
      while (!pq.empty() && pq.top().first < e[0]) {
        auto cur = pq.top();
        pq.pop();
        prev_max = max(prev_max, cur.second);
      }
      // prev_max is still valid for follwing event, why? because prev_max's end time must be 
      // smaller than the follwing event's start time
      // so we just choose biggest valid one before
      ret = max(ret, prev_max + e[2]);
      pq.push({e[1], e[2]});
    }
    return ret;
  }
};
