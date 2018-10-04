// http://leetcode.com/problems/minimum-path-sum/description/
#include "one.h"

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    const int m = grid.size();
    if (m == 0) {
      return 0;
    }
    const int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = grid[0][0];
    for (int j = 0; j < n; ++j) {
      dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    for (int i  =1; i < m ; ++i) {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = min(dp[i - 1][j] + grid[i][j], dp[i][j - 1] + grid[i][j]);
      }
    }
    return dp[m - 1][n - 1];
  }
};

int main() {
  Solution so;
  vector<vector<int>> input{{1,3,1}, {1, 5, 1}, {4, 2, 1}};
  auto ret = so.minPathSum(input);
  cout << ret << endl;
}
