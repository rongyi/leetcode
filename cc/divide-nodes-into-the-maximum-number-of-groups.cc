// https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/
#include "xxx.hpp"

class Solution {
public:
  int magnificentSets(int n, vector<vector<int>> &edges) {
    vector<vector<int>> neibs(n);
    for (auto &e : edges) {
      neibs[e[0] - 1].push_back(e[1] - 1);
      neibs[e[1] - 1].push_back(e[0] - 1);
    }

    vector<int> visited(n);
    vector<vector<int>> groups;
    for (int i = 0; i < n; ++i) {
      if (visited[i]) {
        continue;
      }
      groups.push_back({i});
      vector<int> stk;
      stk.push_back(i);
      visited[i] = 1;
      while (!stk.empty()) {
        auto cur = stk.back();
        stk.pop_back();
        for (auto &next : neibs[cur]) {
          if (!visited[next]) {
            stk.push_back(next);
            visited[next] = visited[cur] + 1;
            groups.back().push_back(next);
          } else if ((visited[next] & 1) == (visited[cur] & 1)) {
            return -1;
          }
        }
      }
    }

    int ans = 0;
    for (auto &g : groups) {
      int cur = 0;
      // start from each node to do a bfs and get the highest
      for (auto &start : g) {
        cur = max(cur, bfs(n, start, neibs));
      }
      ans += cur;
    }

    return ans;
  }

private:
  int bfs(int n, int cur, vector<vector<int>> &neibs) {
    int ret = 0;
    vector<int> visited(n, 0);
    visited[cur] = 1;
    queue<int> q;
    q.push(cur);
    while (!q.empty()) {
      int sz = q.size();
      for (int i = 0; i < sz; ++i) {
        auto cur = q.front();
        q.pop();
        for (auto &next : neibs[cur]) {
          if (!visited[next]) {
            visited[next] = 1;
            q.push(next);
          }
        }
      }
      ret++;
    }
    return ret;
  }
};
