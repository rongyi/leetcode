// http://leetcode.com/problems/is-graph-bipartite/description/
#include "xxx.h"

class Solution {
public:
  bool isBipartite(vector<vector<int>> &graph) {
    // lets say graph node can be painted by two color
    unordered_map<int, bool> paint;
    const int n = graph.size();
    for (int i = 0; i < n; i++) {
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
        // 对端不能跟当前节点一样
        if (paint[nei] == cur_color) {
          return false;
        }
      } else {
        // 不要忽略这个返回值
        if (!dfs(graph, nei, paint, !cur_color)) {
          return false;
        }
      }
    }
    return true;
  }
};

int main() {
  Solution so;
  vector<vector<int>> input{{1}, {0, 3}, {3}, {1, 2}};
  cout << so.isBipartite(input) << endl;
}
