// http://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/description/
#include "xxx.h"
class Solution {
public:
  // minimum sum partion problem
  // dp[i][j] ==> doing j jobs in first i days
  // dp[i][j] = min{ dp[i - 1][k] + max(difficulty[k + 1][j])}
  // i - 1 <= k < j
  int minDifficulty(vector<int> &jobs, int d) {
    const int n = jobs.size();
    // can not be done
    if (d > n) {
      return -1;
    }

    vector<vector<int>> cost(n, vector<int>(n, 0));
    // 单个任务难度就是它自己
    for (int i = 0; i < n; i++) {
      cost[i][i] = jobs[i];
    }
    for (int l = 2; l <= n; l++) {
      for (int i = 0, j = i + l - 1; i <= n - l; i++, j++) {
        cost[i][j] = max(cost[i][j - 1], jobs[j]);
      }
    }

    vector<vector<int>> dp(d, vector<int>(n, 0));
    // 一天全干了，就是难度cost[0][i]里最大的那个
    for (int i = 0; i < n; ++i) {
      dp[0][i] = cost[0][i];
    }

    // 分多天干
    for (int i = 1; i < d; i++) {
      // 每天至少做一件，所以起始为i
      for (int j = i; j < n; ++j) {
        auto opt = numeric_limits<int>::max();
        // 同样是i - 1天需要至少做i - 1个任务，所以k最小值为i - 1
        for (int k = i - 1; k < j; k++) {
          auto sum = dp[i - 1][k] + cost[k + 1][j];
          opt = min(opt, sum);
        }
        dp[i][j] = opt;
      }
    }

    return dp[d - 1][n - 1];
  }
};
