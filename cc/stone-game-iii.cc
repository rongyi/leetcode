// http://leetcode.com/problems/stone-game-iii/description/
#include "xxx.h"

class Solution {
public:
  string stoneGameIII(vector<int> &stoneValue) {
    const int n = stoneValue.size();
    vector<int> dp(n, numeric_limits<int>::min());
    auto ret = dfs(stoneValue, dp, 0);

    if (ret == 0) {
      return "Tie";
    } else if (ret < 0) {
      return "Bob";
    }

    return "Alice";
  }

private:
  int dfs(vector<int> &sv, vector<int> &dp, int cur) {
    if (cur >= sv.size()) {
      return 0;
    }
    if (dp[cur] == numeric_limits<int>::min()) {
      for (auto i = 0, sum = 0; i < 3 && cur + i < sv.size(); ++i) {
        sum += sv[cur + i];
        dp[cur] = max(dp[cur], sum - dfs(sv, dp, cur + i + 1));
      }
    }

    return dp[cur];
  }
};
