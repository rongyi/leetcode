// http://leetcode.com/problems/network-delay-time/description/
#include "xxx.hpp"

class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    unordered_map<int, vector<pair<int, int>>> route;
    for (auto r : times) {
      // 0 index all nodes
      route[r[0] - 1].push_back({r[1] - 1, r[2]});
    }

    vector<bool> visited(n, false);
    // visited[k - 1] = true;

    // actually it's not ttl, it's half ttl, call it anyway
    vector<int> ttl(n, numeric_limits<int>::max());
    ttl[k - 1] = 0;
    // first is weight, second is node
    using pii = pair<int, int>;
    // using pq to always go to min path
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, k - 1});

    while (!pq.empty()) {
      auto p = pq.top();
      pq.pop();
      int start_node = p.second;
      if (visited[start_node]) {
        continue;
      }
      for (auto &nei : route[start_node]) {
        auto end_node = nei.first;
        auto weight = nei.second;
        if (ttl[end_node] > ttl[start_node] + weight) {
          ttl[end_node] = ttl[start_node] + weight;
          pq.push({ttl[end_node], end_node});
        }
      }
      visited[start_node] = true;
    }

    auto max_time = *max_element(ttl.begin(), ttl.end());
    if (max_time == numeric_limits<int>::max()) {
      return -1;
    }
    return max_time;
  }
};
