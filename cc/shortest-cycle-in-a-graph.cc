// https://leetcode.com/problems/shortest-cycle-in-a-graph/
#include "xxx.hpp"

class Solution {
public:
  int findShortestCycle(int n, vector<vector<int>> &edges) {
    vector<set<int>> neibs(n);
    for (auto &e : edges) {
      neibs[e[0]].insert(e[1]);
      neibs[e[1]].insert(e[0]);
    }
    for (int i = 0; i < n; i++) {
      bfs(i, n, neibs);
    }

    if (ret_ == numeric_limits<int>::max()) {
      return -1;
    }

    return ret_;
  }

private:
  void bfs(int src, int n, vector<set<int>> &neibs) {
    vector<int> distance(n, 1e9);
    distance[src] = 0;
    vector<int> parent(n, -1);

    queue<int> q;
    q.push(src);

    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      for (auto &next : neibs[cur]) {
        if (distance[next] == 1e9) {
          parent[next] = cur;
          distance[next] = distance[cur] + 1;
          q.push(next);
        } else if (parent[cur] !=
                   next) { // we don't use visited cache to eliminate the parent
                           // node, so this check filter that case, that mean,
                           // we meet an node which is updated by other same
                           // route, so there is a joint edge

          // common next, a joint point to make a circle
          ret_ = min(ret_, distance[cur] + distance[next] + 1);
        }
      }
    }
  }

private:
  int ret_ = numeric_limits<int>::max();
};
