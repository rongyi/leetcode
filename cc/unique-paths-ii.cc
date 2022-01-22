// http://leetcode.com/problems/unique-paths-ii/description/
#include "xxx.hpp"

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    const int m = obstacleGrid.size();
    const int n = obstacleGrid[0].size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    if (obstacleGrid[0][0] == 0) {
      dp[1][1] = 1;
    }

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (dp[i - 1][j] && obstacleGrid[i - 1][j - 1] == 0) {
          dp[i][j] += dp[i - 1][j];
        }
        if (dp[i][j - 1] && obstacleGrid[i - 1][j - 1] == 0) {
          dp[i][j] += dp[i][j - 1];
        }
      }
    }

    return dp[m][n];
  }
};

int main() {
  Solution so;
  vector<vector<int>> input{{0, 0}};
  auto ret = so.uniquePathsWithObstacles(input);
  cout << ret << endl;
}
