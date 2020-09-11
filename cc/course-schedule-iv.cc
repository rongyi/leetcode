// http://leetcode.com/problems/course-schedule-iv/description/
#include "xxx.h"

class Solution {
public:
  vector<bool> checkIfPrerequisite(int n, vector<vector<int>> &prerequisites,
                                   vector<vector<int>> &queries) {
    vector<vector<bool>> graph(n, vector<bool>(n, false));
    unordered_map<int, vector<int>> table;
    for (auto &req : prerequisites) {
      table[req[0]].push_back(req[1]);
    }

    for (int i = 0; i < n; ++i) {
      vector<bool> visited(n, false);
      dfs(i, i, graph, visited, table);
    }

    vector<bool> ret;
    for (auto &q : queries) {
      ret.push_back(graph[q[0]][q[1]]);
    }

    return ret;
  }
private:
  void dfs(int start, int cur, vector<vector<bool>> &graph,
           vector<bool> &visited, unordered_map<int, vector<int>> &table) {
    if (visited[cur]) {
      return;
    }

    visited[cur] = true;
    if (start != cur) {
      graph[start][cur] = true;
    }

    for (auto &nei : table[cur]) {
      // indirect child layer
      graph[start][nei] = true;
      dfs(start, nei, graph, visited, table);
    }
  }
};
