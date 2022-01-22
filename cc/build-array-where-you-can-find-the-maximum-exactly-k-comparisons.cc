// http://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/description/
#include "xxx.hpp"

class Solution {
public:
  // clang-format off
  // https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/discuss/586576/C%2B%2B-Bottom-Up-Dynamic-Programming-with-Explanation
  // Let ways[i][j][k] be the number of ways to construct an array of length i with maximum element equal to j at a search cost of k.
  // There are two subproblems that contribute to ways[i][j][k]:

  // Clearly, we require ways[i][j][k] += j * ways[i - 1][j][k]. Why? Because if we have an array of length i - 1 with maximum element equal to j at a search cost of k, then we can just append any element from [1, 2, ... j] to this array, and we end up with an array of length i with maximum element equal to j at a search cost of k. Note that neither the search cost nor the maximum element change since we're only appending elements from [1,2, ..., j]. Only the length changes by one.

  // We also require ways[i][j][k] += SUM from x=1 to j-1 of ways[i - 1][x][k - 1] (the sum is inclusive on both ends). This is true because if we have an array of length i - 1 with maximum element (strictly) less than j at a search cost of k - 1, then we can simply append the element j to the end of this array (which adds a comparison cost of one), and we obtain a valid solution.
  // Now the answer is just the sum over all ways[i][x][k] from x = 1 to k because there is no constraint on what the maximum element should be.
  // clang-format on
  // n 多少个数字
  // m 每一个的区间取值
  // l 查询代价
  int numOfArrays(int n, int num_max, int cost) {
    vector<vector<vector<long long>>> dp(
        n + 1,
        vector<vector<long long>>(num_max + 1, vector<long long>(cost + 1, 0)));

    const int mod = 1e9 + 7;

    // 1 <= arr[i] <= m where (0 <= i < n).
    for (int j = 1; j <= num_max; ++j) {
      dp[1][j][1] = 1;
    }

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= num_max; ++j) {
        for (int k = 1; k <= cost; ++k) {
          long long sum = 0;

          //最大值不变所以查询代价不变，[1..j] inclusive
          //的所有元素都可以append过来
          sum = (sum + j * dp[i - 1][j][k]) % mod;

          for (int x = 1; x < j; ++x) {
            sum = (sum + dp[i - 1][x][k - 1]) % mod;
          }
          dp[i][j][k] = (dp[i][j][k] + sum) % mod;
        }
      }
    }

    long long ret = 0;
    // 没有规定最大值，所以全找一遍
    for (int j = 1; j <= num_max; ++j) {
      ret = (ret + dp[n][j][cost]) % mod;
    }

    return ret;
  }
};
