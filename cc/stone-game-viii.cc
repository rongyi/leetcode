// http://leetcode.com/problems/stone-game-viii/description/
#include "xxx.hpp"

class Solution {
public:
  int stoneGameVIII(vector<int> &st) {
    int sz = st.size();
    for (int i = 1; i < sz; ++i) {
      st[i] += st[i - 1];
    }
    int dp = st[sz - 1];
    // Let prefix sum prefix[i] = A[0] + ... + A[i].

    // Let dp[i] be the maximum score difference the current player can get when
    // the game starts at i, i.e. stones 0 ~ i are already merged as a new stone
    // i whose value is prefix[i].

    // Consider dp[i]: assume the current player chooses to merge stones 0 ~ j
    // (i < j < N), according to the dp definition, the maximum score difference
    // the next player can get using the remaining stones is dp[j]. So the score
    // difference the current player gets is prefix[j] - dp[j].

    // The current player will need to try all i < j < N and use the maximum
    // prefix[j] - dp[j] as dp[i]. Thus, we have:

    // dp[i] = max( prefix[j] - dp[j] | i < j <= N - 2 )
    // dp[N - 2] = prefix[N - 1] // when there are only two stones left, the
    // current player must take them all
    // The anser is dp[0].
    for (int i = sz - 2; i > 0; i--) {
      dp = max(dp, st[i] - dp);
    }

    return dp;
  }
};
