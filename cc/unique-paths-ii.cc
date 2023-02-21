// http://leetcode.com/problems/unique-paths-ii/description/
#include "xxx.hpp"

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obs) {
    int m = obs.size();
    int n = obs[0].size();
    vector<vector<long long>> dp(m, vector<long long>(n, 0));

    for (int j = 0; j < n; ++j) {
      if (obs[0][j] == 0) {
        dp[0][j] = 1;
      } else {
        break;
      }
    }
    for (int i = 0; i < m; ++i) {
      if (obs[i][0] == 0) {
        dp[i][0] = 1;
      } else {
        break;
      }
    }

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (obs[i][j] == 1) {
          continue;
        }
        if (obs[i - 1][j] == 0) {
          dp[i][j] += dp[i - 1][j];
        }
        if (obs[i][j - 1] == 0) {
          dp[i][j] += dp[i][j - 1];
        }
      }
    }

    return dp[m - 1][n - 1];
  }
};

