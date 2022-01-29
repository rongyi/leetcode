// https://leetcode.com/problems/maximum-path-quality-of-a-graph/
#include "xxx.hpp"

// some summary
// https://leetcode.com/discuss/general-discussion/655708/Graph-For-Beginners-Problems-or-Pattern-or-Sample-Solutions
class Solution {
public:
  using pii = pair<int, int>;
  int maximalPathQuality(vector<int> &values, vector<vector<int>> &edges,
                         int maxTime) {
    int sz = values.size();
    int ret = values[0];
    // node, time
    vector<vector<pii>> graph(sz);
    for (auto &e : edges) {
      graph[e[0]].push_back({e[1], e[2]});
      // undirected
      graph[e[1]].push_back({e[0], e[2]});
    }
    vector<int> visited(sz, 0);
    //                              node,sore,time
    // score: uniq node weight sum
    // time: path sum
    dfs(graph, values, visited, ret, maxTime, 0, 0, 0);

    return ret;
  }
  void dfs(vector<vector<pii>> &graph, vector<int> &values,
           vector<int> &visited, int &ret, int maxTime, int cur_node,
           int cur_score, int cur_time) {
    if (cur_time > maxTime) {
      return;
    }
    // first visited node or we visited all it's neighbors
    // and back again
    // make sure the uniq summary of node's weight
    if (visited[cur_node] == 0) {
      cur_score += values[cur_node];
    }
    visited[cur_node]++;

    // meet the target node(again)
    if (cur_node == 0) {
      ret = max(ret, cur_score);
    }

    for (auto &it : graph[cur_node]) {
      auto next_node = it.first;
      auto need_time = cur_time + it.second;
      dfs(graph, values, visited, ret, maxTime, next_node, cur_score,
          need_time);
    }

    visited[cur_node]--;
  }
};
