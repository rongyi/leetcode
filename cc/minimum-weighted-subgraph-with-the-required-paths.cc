// https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/
#include "xxx.hpp"

class Solution {
public:
  long long minimumWeight(int n, vector<vector<int>> &edges, int src1, int src2,
                          int dest) {
    using ll = long long;
    using lp = pair<long, long>;
    // for saving shorted path
    vector<ll> dist1(n, numeric_limits<ll>::max());
    vector<ll> dist2(n, numeric_limits<ll>::max());
    vector<ll> rdist(n, numeric_limits<ll>::max());
    // graph
    vector<vector<lp>> graph(n);
    vector<vector<lp>> rgraph(n);
    // build the graph
    for (auto &e : edges) {
      auto from = e[0];
      auto to = e[1];
      auto cost = e[2];
      graph[from].push_back({to, cost});
      rgraph[to].push_back({from, cost});
    }
    auto run = [&](int start, vector<vector<lp>> &graph, vector<ll> &dist) {
      // to the start distance is 0
      dist[start] = 0;
      // {cost, nodej}
      // the current cost to node nodej
      priority_queue<lp, vector<lp>, greater<lp>> pq;
      pq.push({0, start});
      while (!pq.empty()) {
        // cost, node
        auto [cur_cost, cur_node] = pq.top();
        pq.pop();
        // this is a useless path, we should not going down
        if (cur_cost > dist[cur_node]) {
          continue;
        }
        // dijk
        // from start to next, we going through cur_node
        for (auto &[next_node, next_cost] : graph[cur_node]) {
          if (dist[next_node] > dist[cur_node] + next_cost) {
            // save the mininum cost
            dist[next_node] = dist[cur_node] + next_cost;
            // mark the current cost to node: next_node have cost:
            // dist[next_cost]
            pq.push({dist[next_node], next_node});
          }
        }
      }
    };
    run(src1, graph, dist1);
    run(src2, graph, dist2);
    run(dest, rgraph, rdist);
    ll ret = numeric_limits<ll>::max();
    for (int i = 0; i < n; ++i) {
      if (dist1[i] == numeric_limits<ll>::max() ||
          dist2[i] == numeric_limits<ll>::max() ||
          rdist[i] == numeric_limits<ll>::max()) {
        continue;
      }
      ret = min(ret, dist1[i] + dist2[i] + rdist[i]);
    }
    if (ret == numeric_limits<ll>::max()) {
      return -1;
    }

    return ret;
  }
};
