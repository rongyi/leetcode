// https://leetcode.com/problems/reachable-nodes-with-restrictions/
#include "xxx.hpp"

class Solution {
public:
  int reachableNodes(int n, vector<vector<int>> &edges,
                     vector<int> &restricted) {
    vector<vector<int>> node_edges(n);

    for (auto &e : edges) {
      node_edges[e[0]].push_back(e[1]);
      node_edges[e[1]].push_back(e[0]);
    }
    set<int> black_nodes(restricted.begin(), restricted.end());
    // start point is blacked out, shit
    if (black_nodes.count(0)) {
      return 0;
    }

    set<int> visited;
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
      auto sz = q.size();
      for (int i = 0; i < sz; ++i) {
        auto cur = q.front();
        q.pop();
        visited.insert(cur);
        for (auto &ne : node_edges[cur]) {
          if (visited.count(ne)) {
            continue;
          }
          // blacked out
          if (black_nodes.count(ne)) {
            continue;
          }

          q.push(ne);
        }
      }
    }

    return visited.size();
  }
};
