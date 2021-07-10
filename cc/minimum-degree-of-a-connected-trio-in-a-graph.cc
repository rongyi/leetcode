// http://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph/description/
#include "xxx.h"

class Solution {
public:
  int minTrioDegree(int n, vector<vector<int>> &edges) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    vector<int> count(n + 1, 0);
    for (auto &e : edges) {
      dp[e[0]][e[1]] = 1;
      dp[e[1]][e[0]] = 1;
      ++count[e[0]];
      ++count[e[1]];
    }
    int ret = numeric_limits<int>::max();
    for (int t1 = 1; t1 <= n; ++t1) {
      for (int t2 = t1 + 1; t2 <= n; ++t2) {
        if (dp[t1][t2]) {
          for (int t3 = t2 + 1; t3 <= n; ++t3) {
            // 构成一个三角形
            if (dp[t1][t3] && dp[t2][t3]) {
              // 减去内部消耗的出入度 6
              ret = min(ret, count[t1] + count[t2] + count[t3] - 6);
            }
          }
        }
      }
    }
    if (ret == numeric_limits<int>::max()) {
      return -1;
    }
    return ret;
  }
};
