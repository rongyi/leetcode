// http://leetcode.com/problems/course-schedule-ii/description/
#include "xxx.hpp"

class Solution {
public:
  // signature is changed at 2023, last commit is at 2018
  vector<int> findOrder(int sz, vector<vector<int>> &prerequisites) {
    map<int, vector<int>> graph;
    vector<int> in(sz, 0);
    for (auto &preq : prerequisites) {
      // in degress increment for first
      in[preq[0]]++;
      graph[preq[1]].push_back(preq[0]);
    }

    // using queue for this
    queue<int> q;
    for (int i = 0; i < sz; i++) {
      if (in[i] == 0) {
        q.push(i);
      }
    }

    vector<int> order;
    while (!q.empty()) {
      auto cur = q.front();
      order.push_back(cur);
      q.pop();

      for (auto &neib : graph[cur]) {
        in[neib]--;
        if (in[neib] == 0) {
          q.push(neib);
        }
      }
    }

    if (order.size() != sz) {
      return {};
    }

    return order;
  }
};
