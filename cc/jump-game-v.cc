// http://leetcode.com/problems/jump-game-v/description/
#include "xxx.h"

class Solution {
public:
  int maxJumps(vector<int> &arr, int d) {
    const int n = arr.size();
    vector<int> dp(n, 0);

    int ret = 1;
    for (auto i = 0; i < n; ++i) {
      ret = max(ret, dfs(dp, arr, i, d));
    }

    return ret;
  }

private:
  int dfs(vector<int> &dp, vector<int> &arr, int i, int d, int ret = 1) {
    if (dp[i]) {
      return dp[i];
    }
    for (auto j = i + 1;
         // 而且里面的高度都要小，遇到一个符合要求就退出了
         j <= min(i + d, (int)arr.size() - 1) && arr[j] < arr[i]; ++j) {
      ret = max(ret, 1 + dfs(dp, arr, j, d));
    }
    // 同理
    for (auto j = i - 1; j >= max(0, i - d) && arr[j] < arr[i]; --j) {
      ret = max(ret, 1 + dfs(dp, arr, j, d));
    }
    dp[i] = ret;

    return dp[i];
  }
};
