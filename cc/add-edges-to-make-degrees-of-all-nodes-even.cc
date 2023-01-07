// https://leetcode.com/problems/add-edges-to-make-degrees-of-all-nodes-even/
#include "xxx.hpp"

class Solution {
public:
  bool isPossible(int n, vector<vector<int>> &edges) {
    vector<set<int>> neibs(n + 1);
    for (auto &e : edges) {
      neibs[e[0]].insert(e[1]);
      neibs[e[1]].insert(e[0]);
    }
    vector<int> odd_nodes;
    for (int i = 1; i <= n; ++i) {
      if (neibs[i].size() % 2 == 1) {
        odd_nodes.push_back(i);
      }
    }

    if (odd_nodes.size() == 2) {
      // they can connect to a same node or
      // to eachother
      for (int i = 1; i <= n; ++i) {
        if (neibs[odd_nodes[0]].count(i) == 0 &&
            neibs[odd_nodes[1]].count(i) == 0) {
          return true;
        }
      }
    }

    if (odd_nodes.size() == 4) {
      // must connect to themself
      // math pair is:
      // [{0, 1}, {2, 3}]
      // [{0, 2}, {1, 3}]
      // [{0, 3}, {1, 2}]
      return (neibs[odd_nodes[0]].count(odd_nodes[1]) == 0 &&
              neibs[odd_nodes[2]].count(odd_nodes[3]) == 0) ||
             (neibs[odd_nodes[0]].count(odd_nodes[2]) == 0 &&
              neibs[odd_nodes[1]].count(odd_nodes[3]) == 0) ||
             (neibs[odd_nodes[0]].count(odd_nodes[3]) == 0 &&
              neibs[odd_nodes[1]].count(odd_nodes[2]) == 0);
    }

    return odd_nodes.size() == 0;
  }
};
