// http://leetcode.com/problems/super-egg-drop/description/
#include "xxx.h"

class Solution {
public:
  int superEggDrop(int K, int N) {
    // K个鸡蛋 N个step所能测出的最大高度
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
    int m = 0;
    while (dp[m][K] < N) {
      m++;
      for (int k = 1; k <= K; k++) {
        // 分鸡蛋碎了和没碎两种情况
        // if egg break, we can use (k-1) eggs and (s-1) to detect with Q(s- 1, k-1)
        // if egg isn't broken, we can use k eggs and (s-1) step to detech with Q(s - 1, k)
        // So, Q(s, k) = 1 + Q(s - 1, k) + Q(s - 1, k-1)
        dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
      }
    }

    return m;
  }
};
