// http://leetcode.com/problems/minimum-height-trees/description/
#include "xxx.hpp"

class Solution {
public:
  // The basic idea is "keep deleting leaves layer-by-layer, until reach the
  // root." Specifically, first find all the leaves, then remove them. After
  // removing, some nodes will become new leaves. So we can continue remove
  // them. Eventually, there is only 1 or 2 nodes left. If there is only one
  // node left, it is the root. If there are 2 nodes, either of them could be a
  // possible root. Time Complexity: Since each node will be removed at most
  // once, the complexity is O(n).
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    // prepare the data
    vector<int> degree(n, 0);
    vector<vector<int>> neibs(n);
    for (auto &e : edges) {
      neibs[e[0]].push_back(e[1]);
      neibs[e[1]].push_back(e[0]);
      degree[e[0]]++;
      degree[e[1]]++;
    }

    // start from node which degree is 1
    int node_left = n;
    while (node_left > 2) {
      vector<int> outer_layer;
      for (int i = 0; i < n; i++) {
        if (degree[i] == 1) {
          outer_layer.push_back(i);
          // we don't see this layer anymore
          degree[i] = -1;
        }
      }
      for (auto &leaf : outer_layer) {
        for (auto &next : neibs[leaf]) {
          // don't filt the leaf node cause we already set it to negative value
          degree[next] -= 1;
        }
        node_left--;
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
};

