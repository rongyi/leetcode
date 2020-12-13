// http://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/
#include "xxx.h"

class Solution {
public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges) {
    vector<int> in(n, 0);
    vector<int> ret;
    for (auto &e : edges) {
      in[e[1]]++;
    }
    for (int i = 0; i < n; ++i) {
      if (in[i] == 0) {
        ret.push_back(i);
      }
    }

    return ret;
  }
};
