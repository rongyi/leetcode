// http://leetcode.com/problems/minimum-height-trees/description/
#include "simpleone.h"


class Solution {
public:
  // The basic idea is "keep deleting leaves layer-by-layer, until reach the
  // root." Specifically, first find all the leaves, then remove them. After
  // removing, some nodes will become new leaves. So we can continue remove
  // them. Eventually, there is only 1 or 2 nodes left. If there is only one
  // node left, it is the root. If there are 2 nodes, either of them could be a
  // possible root. Time Complexity: Since each node will be removed at most
  // once, the complexity is O(n).
  vector<int> findMinHeightTrees(int n, vector<pair<int, int>> &edges) {
    vector<unordered_set<int>> graph(n);
    for (auto e : edges) {
      graph[e.first].insert(e.second);
      graph[e.second].insert(e.first);
    }

    vector<int> degree(n, 0);
    for (int i = 0; i < n; i++) {
      degree[i] = graph[i].size();
    }

    for (int i = 0, j, remain = n; i < n && remain > 2; i++) {
      vector<int> del;
      for (j = 0; j < n; j++) {
        if (degree[j] == 1) {
          remain--;
          del.push_back(j);
          degree[j] =  -1;
        }
      }
      for (auto k : del) {
        for (auto neigh : graph[k]) {
          degree[neigh]--;
        }
      }
    }
    vector<int> ret;
    for (int i = 0; i < n; i++) {
      if (degree[i] >= 0) {
        ret.push_back(i);
      }
    }

    return ret;
  }

  vector<int> findMinHeightTreesTLE(int n, vector<pair<int, int>> &edges) {
    vector<int> ret;
    unordered_map<int, vector<int>> graph;
    for (auto kv : edges) {
      graph[kv.first].push_back(kv.second);
      graph[kv.second].push_back(kv.first);
    }

    unordered_map<int, int> keydepth;
    int min_depth = numeric_limits<int>::max();
    // calculate
    for (int i = 0; i < n; i++) {
      unordered_set<int> cache;
      auto depth = bfs(graph, cache, i, 0);

      min_depth = min(min_depth, depth);
      keydepth[i] = depth;
    }
    for (auto kv : keydepth) {
      if (kv.second == min_depth) {
        ret.push_back(kv.first);
      }
    }

    return ret;
  }

public:
  int bfs(unordered_map<int, vector<int>> &graph, unordered_set<int> &cache,
          int cur, int depth) {
    if (cache.size() == graph.size()) {
      return depth;
    }
    cache.insert(cur);

    int ret = depth;
    // visited
    auto my_nbs = graph[cur];
    for (auto e : my_nbs) {
      if (cache.find(e) != cache.end()) {
        continue;
      }
      ret = max(ret, bfs(graph, cache, e, depth + 1));
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<pair<int, int>> input{{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
  so.findMinHeightTrees(6, input);
}
