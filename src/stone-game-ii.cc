// http://leetcode.com/problems/stone-game-ii/description/
#include "xxx.h"

class Solution {
public:
  // https://leetcode.com/problems/stone-game-ii/discuss/345404/Simple-DP-Solution-clean-Code
  int stoneGameII(vector<int> &piles) {
    const int n = piles.size();
    vector<int> suffix_sum(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
      suffix_sum[i] = suffix_sum[i + 1] + piles[i];
    }
    // starting at index i with M = j(i.e. Alex can get at most j piles)
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++) {
      // collect them all!
      dp[i][n] = suffix_sum[i];
    }
    for (int i = n - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        for (int cur_pile = 1; cur_pile <= 2 * j && i + cur_pile <= n;
             cur_pile++) {
          dp[i][j] =
              max(dp[i][j], suffix_sum[i] - dp[i + cur_pile][max(j, cur_pile)]);
        }
      }
    }

    return dp[0][1];
  }
};
