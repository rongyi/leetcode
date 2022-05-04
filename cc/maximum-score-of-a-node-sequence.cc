// https://leetcode.com/problems/maximum-score-of-a-node-sequence/
#include "xxx.hpp"

class Solution {
public:
  int maximumScore(vector<int> &scores, vector<vector<int>> &edges) {
    int ret = -1;
    int sz = scores.size();
    vector<vector<int>> groups(sz);
    for (auto &e : edges) {
      groups[e[0]].push_back(e[1]);
      groups[e[1]].push_back(e[0]);
    }
    for (auto &neibs : groups) {
      partial_sort(begin(neibs), begin(neibs) + min((int)neibs.size(), 3),
                   end(neibs),
                   [&](int i, int j) { return scores[i] > scores[j]; });
      neibs.resize(min((int)neibs.size(), 3));
    }
    for (auto &e : edges) {
      int node_left = e[0];
      int node_right = e[1];
      for (auto left_neib : groups[node_left]) {
        for (auto right_neib : groups[node_right]) {
          // make sure they are 4 different nodes
          // 1. neibs not same of two sides
          // 2. neibs not part of those two nodes
          if (right_neib != node_left && left_neib != node_right &&
              left_neib != right_neib) {
            ret = max(ret, scores[node_left] + scores[node_right] +
                               scores[left_neib] + scores[right_neib]);
          }
        }
      }
    }

    return ret;
  }
};
