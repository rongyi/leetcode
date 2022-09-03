// https://leetcode.com/problems/node-with-highest-edge-score/
#include "xxx.hpp"

class Solution {
public:
  // no dfs and bfs
  int edgeScore(vector<int> &edges) {
    int sz = edges.size();
    vector<long long> score(sz, 0);
    for (int i = 0; i < sz; ++i) {
      score[edges[i]] += i;
    }
    long long max_score = 0;
    int idx = -1;
    for (int i = sz - 1; i >= 0; --i) {
      if (score[i] >= max_score) {
        max_score = score[i];
        idx = i;
      }
    }

    return idx;
  }
};
