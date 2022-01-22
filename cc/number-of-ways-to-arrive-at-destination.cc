// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
#include "xxx.hpp"

using pll = pair<long long, long long>;
using ll = long long;
class Solution {
public:
  int countPaths(int n, vector<vector<int>> &roads) {
    vector<vector<pll>> paths(n);
    for (auto &r : roads) {
      // r -> [u, v, weight]
      // {node, weight}
      paths[r[0]].push_back({r[1], r[2]});
      paths[r[1]].push_back({r[0], r[2]});
    }

    return dijkstra(paths, n, 0);
  }

private:
  int dijkstra(vector<vector<pll>> &paths, int n, int start) {
    const int mod = 1e9 + 7;
    // mark the min time for each node
    // this two array are the key struct!
    vector<ll> min_vec(n, numeric_limits<ll>::max());
    vector<ll> ways(n, 0);
    ways[start] = 1;    // one way
    min_vec[start] = 0; // cost zero time for start
    // {cost, node}
    priority_queue<pll, vector<pll>, greater<>> q;
    q.push({0, 0});

    while (!q.empty()) {
      pll cur = q.top();
      // cost to node
      ll cur_cost = cur.first;
      ll cur_node = cur.second;
      q.pop();
      // cut leaf, those paths are already invalid,
      // because we already have a path which cost is
      // lower than this one
      if (cur_cost > min_vec[cur_node]) {
        continue;
      }
      // update next node
      for (pll &neibs : paths[cur_node]) {
        ll next_node = neibs.first;
        ll path_cost = neibs.second;
        if (min_vec[next_node] > cur_cost + path_cost) {
          min_vec[next_node] = cur_cost + path_cost;
          ways[next_node] = ways[cur_node];
          q.push({min_vec[next_node], next_node});
        } else if (min_vec[next_node] == cur_cost + path_cost) {
          ways[next_node] = (ways[next_node] + ways[cur_node]) % mod;
        }
      }
    }

    return ways[n - 1];
  }
};
