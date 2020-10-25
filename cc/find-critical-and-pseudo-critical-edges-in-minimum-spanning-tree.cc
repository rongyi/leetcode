// http://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/description/
#include "xxx.h"

class Solution {
public:
  vector<vector<int>>
  findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges) {
    // add the edge
    for (int i = 0; i < edges.size(); ++i) {
      edges[i].push_back(i);
    }

    vector<int> critical;
    vector<int> pseudo;
    sort(edges.begin(), edges.end(),
         [](auto &a, auto &b) { return a[2] < b[2]; });

    int optimal = mst(n, edges, -1, -1);

    for (int i = 0; i < edges.size(); ++i) {
      if (mst(n, edges, i, -1) > optimal) {
        critical.push_back(edges[i][3]);
      } else if (mst(n, edges, -1, i) == optimal) {
        pseudo.push_back(edges[i][3]);
      }
    }

    return {critical, pseudo};
  }

private:
  // minimum spanning tree
  // edge[i] ==> from, to, weight, index
  int mst(int n, vector<vector<int>> &edges, int ignore_edge, int taken_edge) {
    auto u = UnionFind(n);
    int ret = 0;

    if (taken_edge != -1) {
      auto &cur = edges[taken_edge];
      u.join(cur[0], cur[1]);
      ret += cur[2];
    }

    for (int i = 0; i < edges.size(); ++i) {
      if (i == ignore_edge) {
        continue;
      }
      auto &cur = edges[i];
      auto p1 = u.find(cur[0]);
      auto p2 = u.find(cur[1]);
      if (p1 == p2) {
        continue;
      }
      u.join(cur[0], cur[1]);

      ret += cur[2];
    }

    for (int i = 0; i < n; ++i) {
      if (u.find(i) != u.find(0)) {
        return numeric_limits<int>::max();
      }
    }
    return ret;
  }

  class UnionFind {
  public:
    UnionFind(int n) {
      parent_ = vector<int>(n, 0);
      for (int i = 0; i < n; ++i) {
        parent_[i] = i;
      }
    }
    int find(int n) {
      if (parent_[n] != n) {
        parent_[n] = find(parent_[n]);
      }
      return parent_[n];
    }
    // a ==> b
    bool join(int a, int b) {
      auto p1 = find(a);
      auto p2 = find(b);
      if (p1 == p2) {
        return false;
      }
      parent_[p1] = p2;

      return true;
    }

  private:
    vector<int> parent_;
  };
};
