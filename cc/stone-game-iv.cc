// http://leetcode.com/problems/stone-game-iv/description/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/stone-game-iv/discuss/909380/Recurrence-Tree-Diagram-or-Top-Down-DP-or-Bottom-Up-DP-Visual
  bool winnerSquareGame(int n) {
    vector<bool> dp(n + 1, false);
    // 枚举所有可能，然后看这一步走完对方怎么样？
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j * j <= i; ++j) {
        // 对方输了，那么我赢
        if (!dp[i - j * j]) {
          dp[i] = true;
          break;
        }
      }
    }

    return dp[n];
  }
};
