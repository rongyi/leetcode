// https://leetcode.com/problems/design-graph-with-shortest-path-calculator/
#include "xxx.hpp"

class Graph {
public:
  Graph(int n, vector<vector<int>> &edges) {
    neibs_with_weight_.resize(n);
    for (auto &e : edges) {
      // {endpoint, weight}
      neibs_with_weight_[e[0]].push_back({e[1], e[2]});
    }
  }

  void addEdge(vector<int> edge) {
    neibs_with_weight_[edge[0]].push_back({edge[1], edge[2]});
  }

  int shortestPath(int node1, int node2) {
    // {shorted path, end node}
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    // initial point
    pq.push({0, node1});
    vector<int> cost(neibs_with_weight_.size(), numeric_limits<int>::max());
    cost[node1] = 0;

    while (!pq.empty() && pq.top().second != node2) {
      auto cur = pq.top();
      pq.pop();
      int cur_cost = cur.first;
      int cur_node = cur.second;

      if (cur_cost != cost[cur_node]) {
        continue;
      }
      for (auto &next : neibs_with_weight_[cur_node]) {
        // from current to next, the weight is smaller than
        // found path(or initial unresolved path)
        int next_node = next[0];
        int path_weight = next[1];
        // find a new smaller path to node next_node;
        if (cur_cost + path_weight < cost[next_node]) {
          cost[next_node] = cur_cost + path_weight;
          pq.push({cost[next_node], next_node});
        }
      }
    }

    return cost[node2] == numeric_limits<int>::max() ? -1 : cost[node2];
  }

private:
  vector<vector<array<int, 2>>> neibs_with_weight_;
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
