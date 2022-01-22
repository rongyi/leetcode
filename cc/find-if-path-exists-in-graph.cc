// https://leetcode.com/problems/find-if-path-exists-in-graph/
#include "xxx.hpp"

class Solution {
public:
  bool validPath(int n, vector<vector<int>> &edges, int start, int end) {
    vector<int> u(n, 0);
    iota(u.begin(), u.end(), 0);

    for (auto e : edges) {
      bind(u, e[0], e[1]);
    }
    return findParent(u, start) == findParent(u, end);
  }

private:
  void bind(vector<int> &lst, int u, int v) {
    auto pu = findParent(lst, u);
    auto pv = findParent(lst, v);
    lst[pu] = pv;
  }
  int findParent(vector<int> &lst, int node) {
    if (lst[node] == node) {
      return node;
    }

    lst[node] = findParent(lst, lst[node]);

    return lst[node];
  }
};

class SolutionBFS {
public:
  bool validPath(int n, vector<vector<int>> &edges, int start, int end) {
    map<int, vector<int>> path;
    for (auto &e : edges) {
      path[e[0]].push_back(e[1]);
      path[e[1]].push_back(e[0]);
    }
    queue<int> q;
    q.push(start);

    vector<int> visited(n, 0);
    visited[start] = 1;

    while (!q.empty()) {
      auto cur = q.front();
      q.pop();

      if (cur == end) {
        return true;
      }

      for (auto next_node : path[cur]) {
        if (!visited[next_node]) {
          q.push(next_node);
          visited[next_node] = 1;
        }
      }
    }

    return false;
  }
};
