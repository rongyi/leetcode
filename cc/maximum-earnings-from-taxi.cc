// https://leetcode.com/problems/maximum-earnings-from-taxi/
#include "xxx.h"

class Solution {
public:
  long long maxTaxiEarnings(int n, vector<vector<int>> &rides) {
    sort(rides.begin(), rides.end());
    vector<long long> dp(n + 1);
    int j = 0;
    for (int i = 1; i <= n; ++i) {
      // don't pick current
      dp[i] = max(dp[i], dp[i - 1]);
      // pick client at current start
      while (j < rides.size() && rides[j][0] == i) {
        dp[rides[j][1]] = max(dp[rides[j][1]],
                              dp[i] + rides[j][1] - rides[j][0] + rides[j][2]);
        j++;
      }
    }

    return dp[n];
  }
};

class SolutionTLE {
public:
  long long maxTaxiEarnings(int n, vector<vector<int>> &rides) {
    sort(rides.begin(), rides.end());
    return dfs(rides, 0, 0);
  }
  int dfs(vector<vector<int>> &rides, int valid_start, int pos) {
    if (pos >= rides.size()) {
      return 0;
    }
    int earn = 0;
    // can i pick pos?
    if (rides[pos][0] >= valid_start) {
      earn = max(earn, rides[pos][1] - rides[pos][0] + rides[pos][2] +
                           dfs(rides, rides[pos][1], pos + 1));
    }

    // don't pick current
    earn = max(earn, dfs(rides, valid_start, pos + 1));

    return earn;
  }
};
