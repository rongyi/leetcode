// https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/
#include "xxx.hpp"

class Solution {
public:
  int minGroups(vector<vector<int>> &intervals) {
    vector<int> cnt(1e6 + 2, 0);
    for (auto &v : intervals) {
      cnt[v[0]] += 1;
      cnt[v[1] + 1] -= 1;
    }
    for (int i = 1; i < cnt.size(); ++i) {
      cnt[i] += cnt[i - 1];
    }
    int ret = 0;
    for (auto cur : cnt) {
      ret = max(ret, cur);
    }

    return ret;
  }
};

class SolutionA {
public:
  int minGroupsTTL(vector<vector<int>> &intervals) {
    using pp = pair<int, int>;
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    priority_queue<pp, vector<pp>, greater<pp>> pq2;

    int sz = intervals.size();
    int picked = 0;
    for (auto &itv : intervals) {
      pq.push({itv[0], itv[1]});
    }

    auto prev_end = -1;
    int groups = 0;
    while (picked < sz) {
      while (!pq.empty()) {
        auto [cur_start, cur_end] = pq.top();
        pq.pop();
        // ok, they can be put in one group
        if (cur_start > prev_end) {
          prev_end = cur_end;
          picked += 1;
        } else {
          pq2.push({cur_start, cur_end});
        }
      }

      pq.swap(pq2);
      prev_end = -1;
      groups += 1;
    }

    return groups;
  }
};
