// http://leetcode.com/problems/new-21-game/description/
#include "xxx.h"

class Solution {
public:
  double new21Game(int N, int K, int W) {
    if (K == 0 || N >= K + W) {
      return 1.0;
    }
    vector<double> dp(N + 1);
    dp[0] = 1.0;

    double Wsum = 1.0;
    double ret = 0.0;
    for (int i = 1; i <= N; i++) {
      dp[i] = Wsum / W;
      if (i < K) {
        Wsum += dp[i];
      } else {
        // 游戏>= k就停止了
        ret += dp[i];
      }
      if (i - W >= 0) {
        // i - W滑动窗口
        Wsum -= dp[i - W];
      }
    }

    return ret;
  }
};
