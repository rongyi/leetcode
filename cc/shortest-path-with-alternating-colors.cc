// http://leetcode.com/problems/shortest-path-with-alternating-colors/description/
#include "xxx.h"

class Solution {
public:
  // 一个节点裂变成两个，代表两个颜色，然后
  // 红边有蓝色节点出，进红色节点
  // 蓝边由红色节点出，进蓝色节点
  // 这样就形成一种交替
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &red_edges,
                                       vector<vector<int>> &blue_edges) {
    buildGraphEdges(n, red_edges, blue_edges);
    dist_.resize(n, numeric_limits<int>::max());

    bfs(n, 0);
    bfs(n, 1);
    for (int i = 0; i < n; ++i) {
      if (dist_[i] == numeric_limits<int>::max()) {
        dist_[i] = -1;
      }
    }
    return dist_;
  }

private:
  void buildGraphEdges(int n, vector<vector<int>> &red_edges,
                       vector<vector<int>> &blue_edges) {
    node_edges_.resize(2 * n, vector<int>{});
    // 红色偶序编号
    // 蓝色奇数编号
    for (auto e : red_edges) {
      // 从蓝色出，入红色节点
      node_edges_[e[0] * 2 + 1].push_back(e[1] * 2 + 0);
    }
    for (auto e : blue_edges) {
      // 从红色节点出，入蓝色节点
      node_edges_[e[0] * 2 + 0].push_back(e[1] * 2 + 1);
    }
  }
  void bfs(int n, int start_node) {
    queue<int> q;
    q.push(start_node);

    vector<bool> visited(2 * n, false);
    visited[start_node] = true;

    int cur_dist = 0;
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        int cur_node = q.front();
        q.pop();
        dist_[cur_node / 2] = min(dist_[cur_node / 2], cur_dist);
        for (auto next : node_edges_[cur_node]) {
          if (!visited[next]) {
            q.push(next);
            visited[next] = true;
          }
        }
      }
      ++cur_dist;
    }
  }

private:
  vector<int> dist_;
  vector<vector<int>> node_edges_;
};
