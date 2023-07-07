// https://leetcode.com/problems/modify-graph-edge-weights/
#include "xxx.hpp"

class Solution {
public:
  // Dijkstra Algorithm
  vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges,
                                         int source, int destination,
                                         int target) {
    vector<vector<array<int, 2>>> neibs(n);
    for (auto &e : edges) {
      if (e[2] == -1) {
        continue;
      }
      neibs[e[0]].push_back({e[1], e[2]});
      neibs[e[1]].push_back({e[0], e[2]});
    }
    vector<int> dist = find(n, neibs, source, destination);
    // no way
    if (dist[destination] < target) {
      return {};
    }
    if (dist[destination] == target) {
      // set every -1 to biggest num
      for (auto &e : edges) {
        if (e[2] == -1) {
          e[2] = 2e9;
        }
      }
      return edges;
    }
    for (int i = 0; i < edges.size(); i++) {
      auto u = edges[i][0];
      auto v = edges[i][1];
      auto w = edges[i][2];
      if (edges[i][2] == -1) {
        edges[i][2] = 1;
        neibs[u].push_back({v, 1});
        neibs[v].push_back({u, 1});
        vector<int> dist = find(n, neibs, source, destination);
        if (dist[destination] <= target) {
          edges[i][2] += (target - dist[destination]);
          for (int j = i + 1; j < edges.size(); j++) {
            if (edges[j][2] == -1) {
              edges[j][2] = 2e9;
            }
          }
          return edges;
        }
      }
    }
    return {};
  }

private:
  vector<int> find(int n, vector<vector<array<int, 2>>> &neibs, int src,
                   int destination) {
    vector<int> dist(n + 1, 1e9 + 10);
    // weight, target
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, src});
    dist[src] = 0;
    vector<int> visited(n + 1, 0);

    while (!pq.empty()) {
      auto [curw, curnode] = pq.top();
      pq.pop();
      if (visited[curnode]) {
        continue;
      }
      visited[curnode] = true;

      for (auto &[next_node, next_weight] : neibs[curnode]) {
        if (dist[next_node] > curw + next_weight) {
          dist[next_node] = next_weight + curw;
          pq.push({dist[next_node], next_node});
        }
      }
    }

    return dist;
  }
};
