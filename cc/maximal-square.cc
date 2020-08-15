// http://leetcode.com/problems/maximal-square/description/

#include "xxx.h"


// This problem can be solved by dynamic programming. They key to DP is the state equation. In this problem, we define the state as the maximal size of the square that can be achieved at point (i, j), denoted as dp[i][j]. Remember that we use size instead of square as the state (square = size * size).

// Now let's try to come up with the formula for dp[i][j].

// First, it is obvious that for the topmost row (i = 0) and the leftmost column (j = 0), dp[i][j] = matrix[i][j]. For example, if he topmost row of matrix is [1, 0, 0, 1], we immediately know that the first and last point can be a square of size 1 while the two middle points cannot make any square, giving a size of 0. Thus, dp = [1, 0, 0, 1], which is the same as matrix. The case is similar for the leftmost column. Till now, the boundary conditions of this DP problem are solved.

// Let's move to the more general case for dp[i][j] in which i > 0 and j > 0. First of all, let's see a simple sub-case in which matrix[i][j] = 0. It is obvious that dp[i][j] = 0 since if matrix[i][j] = 0, no square will contain matrix[i][j]. According to our definition of dp[i][j], dp[i][j] is also 0.

// Now we are almost done. The remaining sub-case is matrix[i][j] = 1. Suppose matrix = [[0, 1], [1, 1]], it is obvious that dp[0][0] = 0, dp[0][1] = dp[1][0] = 1, what about dp[1][1]? Well, to give a square of size larger than 1 in dp[1][1], all of its three neighbors (left, upper, upper-left) should be non-zero. In this case, the upper-left neighbor dp[0][0] = 0, so dp[1][1] can only be 1, which means that the square only contains matrix[1][1]. To summarize, dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1 in this case.

// The state equations are finally as follows.

// dp[0][j] = matrix[0][j] (topmost row);
// dp[i][0] = matrix[i][0] (leftmost column);
// For i > 0 and j > 0: if matrix[i][j] = 0, dp[i][j] = 0; if matrix[i][j] = 1, dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1.

class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    int ret = 0;
    const int m = matrix.size();
    if (m == 0) {
      return ret;
    }
    const int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // 第一行能形成正方形就在于当前节点是不是1
    for (int j =0; j < n; j++) {
      dp[0][j] = matrix[0][j] - '0';
      ret = max(ret, dp[0][j]);
    }
    // 第一列也是
    for (int i = 0; i < m; i++) {
      dp[i][0] = matrix[i][0] - '0';
      ret = max(ret, dp[i][0]);
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (matrix[i][j] == '1') {
          dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
          ret = max(dp[i][j], ret);
        }
      }
    }

    // return area!
    return ret * ret;
  }
};
