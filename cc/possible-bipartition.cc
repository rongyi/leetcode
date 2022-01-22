// http://leetcode.com/problems/possible-bipartition/description/
#include "xxx.hpp"

class Solution {
public:
  bool possibleBipartition(int N, vector<vector<int>> &dislikes) {
    // 本质上还是着色问题
    vector<vector<int>> graph(N + 1, vector<int>{});

    for (auto &hate_pair : dislikes) {
      graph[hate_pair[0]].push_back(hate_pair[1]);
      graph[hate_pair[1]].push_back(hate_pair[0]);
    }

    // 问题的答案在于能不能用两个颜色着色
    unordered_map<int, bool> paint;
    // const int n = graph.size();
    for (int i = 1; i <= N; i++) {
      if (paint.find(i) == paint.end()) {
        if (!dfs(graph, i, paint, true)) {
          return false;
        }
      }
    }
    return true;
  }

private:
  bool dfs(vector<vector<int>> &graph, int cur_node,
           unordered_map<int, bool> &paint, bool cur_color) {
    // 已经着色过了
    if (paint.find(cur_node) != paint.end()) {
      return paint[cur_node] == cur_color;
    }
    paint[cur_node] = cur_color;
    for (auto nei : graph[cur_node]) {
      if (paint.find(nei) != paint.end()) {
        // 这个对端已经被着色，那么这个颜色不能跟当前节点颜色相同
        // 对端不能跟当前节点一样
        if (paint[nei] == cur_color) {
          return false;
        }
      } else {
        // 没有被着色，那这个对端着色和当前节点相异，然后一路走下去
        // 不要忽略这个返回值
        if (!dfs(graph, nei, paint, !cur_color)) {
          return false;
        }
      }
    }
    return true;
  }
};
