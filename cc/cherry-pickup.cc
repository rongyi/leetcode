// http://leetcode.com/problems/cherry-pickup/description/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/cherry-pickup/discuss/109906/Annotated-C%2B%2B-DP-Solution
  // 详细理解可以参考这个链接
  // https://blog.csdn.net/luke2834/article/details/79365645
  int cherryPickup(vector<vector<int>> &grid) {
    const int n = grid.size();
    // dp[i][j] 表示什么?
    // 假设两个人同时从(0, 0)出发，两人步调一致，那么就表示同样消耗了k个步骤
    //（假设速度为1的话也就 是过k个时间)各自停留的x坐标,
    // first person stop at (i, k - i) and
    // second person stop at (j, k - j) i may equal to j
    vector<vector<int>> dp(n, vector<int>(n, -1));
    dp[0][0] = grid[0][0];

    // k就是每一步
    for (int k = 1, maxK = 2 * n - 2; k <= maxK; ++k) {
      // 从后往前推，这样用一个dp就可以了
      for (int i = min(n - 1, k); i >= 0; --i) {
        // i和k的区间保证了y坐标k - i一定是 >= 0
        if (k - i >= n) {
          continue;
        }
        for (int j = min(n - 1, k); j >= 0; --j) {
          if (k - j >= n || grid[i][k - i] < 0 || grid[j][k - j] < 0) {
            dp[i][j] = -1;
            continue;
          }
          int cherris = dp[i][j];
          if (i > 0) {
            cherris = max(cherris, dp[i - 1][j]);
          }
          if (j > 0) {
            cherris = max(cherris, dp[i][j - 1]);
          }
          if (i > 0 && j > 0) {
            cherris = max(cherris, dp[i - 1][j - 1]);
          }
          if (cherris < 0) {
            continue;
          }
          dp[i][j] = cherris + grid[i][k - i];
          if (i != j) {
            dp[i][j] += grid[j][k - j];
          }
        }
      }
    }
    return max(dp[n - 1][n - 1], 0);
  }
};
