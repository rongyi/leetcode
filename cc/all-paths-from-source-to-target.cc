// http://leetcode.com/problems/all-paths-from-source-to-target/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> ret;
    dfs(graph, 0, {}, ret);
    return ret;
  }
private:
  void dfs(vector<vector<int>> &graph, int cur_node, vector<int> path, vector<vector<int>> &ret) {
    path.push_back(cur_node);
    if (cur_node == graph.size() - 1) {
      ret.push_back(path);
    }
    for (auto n : graph[cur_node]) {
      dfs(graph, n, path, ret);
    }
  }
};
