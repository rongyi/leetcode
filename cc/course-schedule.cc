// http://leetcode.com/problems/course-schedule/description/
#include "xxx.hpp"

class Solution {
public:
  bool canFinish(int sz, vector<vector<int>> &prerequisites) {
    vector<int> indegree(sz, 0);
    vector<int> visited(sz, false);
    // a directed graph
    map<int, vector<int>> graph;
    for (auto &preq : prerequisites) {
      indegree[preq[0]]++;
      graph[preq[1]].push_back(preq[0]);
      // no reverse insert!
    }

    for (int i = 0; i < sz; i++) {
      if (indegree[i] == 0 && !visited[i]) {
        dfs(i, visited, graph, indegree);
      }
    }

    return all_of(indegree.begin(), indegree.end(),
                  [](int i) { return i == 0; });
  }

private:
  void dfs(int cur, vector<int> &visited, map<int, vector<int>> &graph,
           vector<int> &in) {
    visited[cur] = true;
    // learn successive course
    for (auto &neib : graph[cur]) {
      in[neib]--;
      if (!visited[neib] && in[neib] == 0) {
        dfs(neib, visited, graph, in);
      }
    }
  }
};
