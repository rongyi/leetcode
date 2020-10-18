// http://leetcode.com/problems/allocate-mailboxes/description/
#include "xxx.h"

class Solution {
public:
  int minDistance(vector<int> &houses, int k) {
    const int n = houses.size();
    vector<vector<vector<int>>> cache(
        n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));

    sort(houses.begin(), houses.end());

    return dfs(houses, 0, 0, k, cache);
  }

private:
  // i the position of the current house
  // j the position of the first house of current neighborhood
  // k the number of remaining neighborhood
  int dfs(vector<int> &h, int i, int j, int k,
          vector<vector<vector<int>>> &dp) {
    if (i >= h.size() || k <= 0) {
      return i == h.size() && k == 0 ? 0 : numeric_limits<int>::max();
    }
    if (dp[i][j][k]) {
      return dp[i][j][k];
    }

    // start new neighborhood from i
    dp[i][j][k] = dfs(h, i + 1, i + 1, k - 1, dp);
    if (dp[i][j][k] != numeric_limits<int>::max()) {
      for (auto p = j; p <= i; ++p) {
        dp[i][j][k] += abs(h[(i + j) / 2] - h[p]);
      }
    }

    return dp[i][j][k] =
               min(dp[i][j][k], dfs(h, i + 1, j, k, dp)); // 续在当前的"邻居"上
  }
};
