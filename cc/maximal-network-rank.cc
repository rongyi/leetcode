// http://leetcode.com/problems/maximal-network-rank/description/
#include "xxx.h"

class Solution {
public:
  // 看懂题目意思：
  int maximalNetworkRank(int n, vector<vector<int>> &roads) {
    vector<unordered_set<int>> groups(n);

    for (auto &p : roads) {
      groups[p[0]].insert(p[1]);
      groups[p[1]].insert(p[0]);
    }
    int ret = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int cur = groups[i].size() + groups[j].size();
        if (groups[j].count(i)) {
          cur--;
        }
        ret = max(ret, cur);
      }
    }

    return ret;
  }
};
