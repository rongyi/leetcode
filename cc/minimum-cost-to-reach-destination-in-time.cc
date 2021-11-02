// https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/
#include "xxx.h"

class Solution {
public:
  int minCost(int maxTime, vector<vector<int>> &edges,
              vector<int> &passingFees) {
    int n = passingFees.size();
    // make compare not equal
    vector<int> min_time(n, maxTime + 1);
    // don't turn back to zero node
    min_time[0] = 0;
    // [x][y] ==> time
    vector<unordered_map<int, int>> graph(n);
    for (auto &e : edges) {
      int x = e[0];
      int y = e[1];
      int time = e[2];
      // multiple road between two nodes
      // we take the smallest time, because fee is at node
      // not edge
      if (graph[x].count(y)) {
        graph[x][y] = min(graph[x][y], time);
        graph[y][x] = min(graph[y][x], time);
      } else {
        graph[x][y] = time;
        graph[y][x] = time;
      }
    }
    auto cmp = [](auto &a, auto &b) -> bool { return a[2] > b[2]; };
    // node, time, fee
    using a3 = array<int, 3>;
    priority_queue<a3, vector<a3>, decltype(cmp)> pq(cmp);
    pq.push({0, 0, passingFees[0]});
    while (!pq.empty()) {
      auto [cur_node, cur_time, cur_fee] = pq.top();
      pq.pop();
      // last node?
      if (cur_node == n - 1) {
        return cur_fee;
      }
      for (auto &[next_node, nex_time] : graph[cur_node]) {
        int cost_time = cur_time + nex_time;
        int cost_fee = cur_fee + passingFees[next_node];
        // time limit within limit
        // keep press!
        if (cost_time < min_time[next_node]) {
          min_time[next_node] = cost_time;
          pq.push({next_node, cost_time, cost_fee});
        }
      }
    }

    return -1;
  }
};
