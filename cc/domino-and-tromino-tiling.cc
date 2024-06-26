// http://leetcode.com/problems/domino-and-tromino-tiling/description/
// ../image/domino.png
#include "xxx.hpp"
class Solution {
public:
  // dp[n] = dp[n-1] + dp[n-2] + 2 * (dp[n-3] + ... + dp[0])
  //       = dp[n-1] + dp[n-3] + dp[n-2] + dp[n-3] + 2 * (dp[n-4] + ... dp[0])
  //       = dp[n-1] + dp[n-3] + dp[n-1]
  //       = 2 * dp[n-1] + dp[n-3]
  int numTilings(int N) {
    const static int m = 1e9 + 7;
    vector<long> dp(N + 1);
    dp[0] = 1;
    dp[1] = 1;
    if (N <= 1) {
      return dp[N];
    }
    dp[2] = 2;
    for (int i = 3; i <= N; ++i) {
      dp[i] = (dp[i - 1] * 2 + dp[i - 3]) % m;
    }

    return dp[N];
  }
};
