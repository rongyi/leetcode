// https://leetcode.com/problems/collect-coins-in-a-tree/
#include "xxx.hpp"

class Solution {
public:
  int collectTheCoins(vector<int> &coins, vector<vector<int>> &edges) {
    int sz = coins.size();
    // undirectd edge
    int total_edges = edges.size() * 2;
    int cut_edge = 0;

    vector<set<int>> neibs(sz);

    for (auto &e : edges) {
      neibs[e[0]].insert(e[1]);
      neibs[e[1]].insert(e[0]);
    }
    queue<int> leafq;
    for (int i = 0; i < sz; i++) {
      // must be useless leaf, aka no coin
      if (neibs[i].size() == 1 && coins[i] == 0) {
        leafq.push(i);
      }
    }
    while (!leafq.empty()) {
      auto cur = leafq.front();
      leafq.pop();
      if (neibs[cur].empty()) {
        continue;
      }
      int p = *neibs[cur].begin();
      // cut the edge!
      neibs[cur].erase(p);
      neibs[p].erase(cur);
      cut_edge += 2;
      if (neibs[p].size() == 1 && coins[p] == 0) {
        leafq.push(p);
      }
    }
    // now we drop all useless leaf
    // we now drop two out most layers
    int layers = 2;
    // still use leafq, but now its empty
    // find leaf node again
    for (int i = 0; i < sz; i++) {
      // delete blindly, don't care have coin or not
      if (neibs[i].size() == 1) {
        leafq.push(i);
      }
    }

    while (layers--) {
      int qsz = leafq.size();
      while (qsz--) {
        auto cur = leafq.front();
        leafq.pop();
        if (neibs[cur].empty()) {
          continue;
        }
        // cut again
        int p = *neibs[cur].begin();
        neibs[p].erase(cur);
        neibs[cur].erase(p);
        if (neibs[p].size() == 1) {
          leafq.push(p);
        }
        cut_edge += 2;
      }
    }

    return total_edges - cut_edge;
  }
};
