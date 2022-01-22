// http://leetcode.com/problems/new-21-game/description/
#include "xxx.hpp"

// https://leetcode.com/problems/new-21-game/discuss/132334/One-Pass-DP-O(N)
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
        // i - W滑动窗口, 为毛不是 i - W - 1
        // 因为这里的减是为下一次做准备的
        // 所以这里的差1隐含了
        Wsum -= dp[i - W];
      }
    }

    return ret;
  }
};
