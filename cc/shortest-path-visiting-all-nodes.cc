// http://leetcode.com/problems/shortest-path-visiting-all-nodes/description/
#include "xxx.hpp"

class Solution {
public:
  int shortestPathLength(vector<vector<int>> &graph) {
    ret_ = numeric_limits<int>::max();
    vector<int> cur;
    vector<int> visited(graph.size(), 0);

    int cur_count = 0;
    for (int i = 0; i < graph.size(); i++) {
      cur.push_back(i);
      visited[i]++;
      cur_count++;
      dfs(graph, cur, visited, cur_count);
      cur_count--;
      visited[i]--;
      cur.pop_back();
    }
    return ret_ - 1;
  }

private:
  void dfs(vector<vector<int>> &graph, vector<int> &cur, vector<int> &visited,
           int cur_count) {
    if (ret_ == graph.size()) {
      return;
    }
    if (cur_count == graph.size()) {
      ret_ = min(ret_, int(cur.size()));
    }
    if (cur.size() >= ret_) {
      return;
    }
    int pos = cur.back();

    int minv = numeric_limits<int>::max();
    for (auto n : graph[pos]) {
      minv = min(minv, visited[n]);
    }
    for (auto n : graph[pos]) {
      if (visited[n] == minv) {
        cur.push_back(n);
        if (!visited[n]) {
          cur_count++;
        }
        visited[n]++;
        dfs(graph, cur, visited, cur_count);
        visited[n]--;
        if (!visited[n]) {
          cur_count--;
        }
        cur.pop_back();
      }
    }
  }

private:
  int ret_;
};
