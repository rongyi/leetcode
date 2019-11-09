// http://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/description/
#include "xxx.h"

class Solution {
public:
  using graph = unordered_map<int, vector<int>>;
  vector<int> sortItems(int n, int m, vector<int> &group,
                        vector<vector<int>> &beforeItems) {
    // group之间的依赖
    graph inter;
    vector<graph> inner(m);
    // 没有group的那些也给他分一个独立的group
    for (int i = 0; i < group.size(); ++i) {
      if (group[i] == -1) {
        group[i] = m++;
        inner.resize(m);
      }
      inter[group[i]];
      inner[group[i]][i];
    }
    // group内部的依赖

    // 第i个节点前面必须要存在bi节点
    for (int i = 0; i < n; ++i) {
      for (auto const &bi : beforeItems[i]) {
        if (group[i] == group[bi]) {
          inner[group[bi]][bi].push_back(i);
        } else {
          inter[group[bi]].push_back(group[i]);
        }
      }
    }

    // inter group
    list<int> group_order;
    if (!topo_sort(inter, group_order)) {
      return {};
    }

    vector<list<int>> inner_order(m);
    for (int i = 0; i < m; ++i) {
      if (!topo_sort(inner[i], inner_order[i])) {
        return {};
      }
    }

    list<int> ret;
    for (auto &i : group_order) {
      ret.splice(ret.end(), inner_order[i]);
    }

    return vector<int>(ret.begin(), ret.end());
  }

private:
  bool topo_sort(graph &g, list<int> &topo) {
    unordered_map<int, int> visited;
    for (const auto &kv : g) {
      if (!dfs(kv.first, g, topo, visited)) {
        return false;
      }
    }
    return true;
  }
  bool dfs(int i, graph &g, list<int> &topo, unordered_map<int, int> &visited) {
    if (visited[i] == -1) {
      return false;
    }
    if (visited[i] == 0) {
      visited[i] = -1;
      for (auto &j : g[i]) {
        if (!dfs(j, g, topo, visited)) {
          return false;
        }
      }
      visited[i] = 1;
      topo.push_front(i);
    }

    return true;
  }
};
