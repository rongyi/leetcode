// http://leetcode.com/problems/redundant-connection/description/
#include "xxx.h"

class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    vector<int> parent(edges.size() + 1, 0);
    for (int i = 0; i < parent.size(); i++) {
      parent[i] = i;
    }
    vector<int> ret;

    for (auto &e : edges) {
      int v1 = e[0];
      int v2 = e[1];
      while (parent[v1] != v1) {
        v1 = parent[v1];
      }
      while (parent[v2] != v2) {
        v2 = parent[v2];
      }
      if (v1 == v2) {
        ret = e;
      }
      parent[v1] = v2;
    }

    return ret;
  }
};
