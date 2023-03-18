// http://leetcode.com/problems/triangle/description/
#include "xxx.hpp"

class Solution {
public:
  int minimumTotal(vector<vector<int>> &lst) {
    int m = lst.size();
    vector<vector<int>> dp(m, vector<int>(m, 0));

    dp[0][0] = lst[0][0];
    for (int i = 1; i < m; i++) {
      auto &cur_row = lst[i];
      int sz = cur_row.size();
      dp[i][0] = dp[i - 1][0] + cur_row[0];
      dp[i][sz - 1] = dp[i - 1][sz - 2] + cur_row[sz - 1];

      for (int j = 1; j < sz - 1; j++) {
        dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + cur_row[j];
      }
    }

    return *min_element(dp[m - 1].begin(), dp[m - 1].end());
  }
};

