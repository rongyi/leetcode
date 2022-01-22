// http://leetcode.com/problems/pizza-with-3n-slices/description/
#include "xxx.hpp"

class Solution {
public:
  int maxSizeSlices(vector<int> &slices) {
    // dp[i][j] we pick `j` elements from linear array `i` elements
    const int m = slices.size();
    const int n = m / 3;

    auto pick = [&](const auto &arr, const int cnt, const int n) {
      vector<vector<int>> dp(cnt + 1, vector<int>(n + 1));
      for (int i = 1; i <= cnt; ++i) {
        for (int j = 1; j <= n; ++j) {
          // So there are total 2 cases, then we can return the case with
          // maximum sum:

          // Case 1: Don't pick (m-1)th element
          // => Solve problem: pick n non-adjacent elements from linear array
          // elements in ranges [0..m-2] so that the sum of the elements is
          // maximum.

          // Case 2: Don't pick 0th element
          // => Solve problem: pick n non-adjacent elements from linear array
          // elements in ranges [1..m-1] so that the sum of the elements is
          // maximum.
          if (i == 1) {
            dp[i][j] = arr[0];
          } else {
            // 因为不能取相邻所以取了之后的i空间变成了 i - 2
            dp[i][j] = max(dp[i - 1][j], dp[i - 2][j - 1] + arr[i - 1]);
          }
        }
      }
      return dp[cnt][n];
    };

    // 1. pick 0..m-2
    // 2. pick 1..m-1
    return max(pick(slices.begin(), m - 1, n),
               pick(slices.begin() + 1, m - 1, n));
  }
};
