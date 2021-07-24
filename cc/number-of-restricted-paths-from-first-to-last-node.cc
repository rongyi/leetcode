// http://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/description/
#include "xxx.h"

class Solution {
  using pii = pair<int, int>;

public:
  int countRestrictedPaths(int n, vector<vector<int>> &edges) {
    mod_ = 1e9 + 7;
    // first calculate the shortest distance to n
    vector<int> dist(n + 1, 0);
    vector<vector<pii>> em(n + 1);
    // [node(i), node(j), dis(i, j)]
    for (auto &e : edges) {
      em[e[0]].push_back({e[1], e[2]});
      em[e[1]].push_back({e[0], e[2]});
    }
    // distance, node
    priority_queue<pii, vector<pii>> pq;
    pq.push({0, n});
    while (!pq.empty()) {
      auto cur_node = pq.top().second;
      pq.pop();
      for (auto [nei, d] : em[cur_node]) {
        if (nei != n && (dist[nei] == 0 || dist[nei] > dist[cur_node] + d)) {
          dist[nei] = dist[cur_node] + d;
          pq.push({-dist[nei], nei});
        }
      }
    }
    vector<int> dp(n + 1, -1);
    return dfs(1, n, dp, dist, em);
  }

private:
  int dfs(int node, int end, vector<int> &dp, vector<int> &dist,
          vector<vector<pii>> &em) {
    // 找到一条
    if (node == end) {
      return 1;
    }
    if (dp[node] != -1) {
      return dp[node];
    }
    dp[node] = 0;
    for (auto [nei, d] : em[node]) {
      // 后面的节点与n的距离都要比当前节点近才可以
      if (dist[node] > dist[nei]) {
        dp[node] = (dp[node] + dfs(nei, end, dp, dist, em)) % mod_;
      }
    }

    return dp[node];
  }

private:
  int mod_;
};
