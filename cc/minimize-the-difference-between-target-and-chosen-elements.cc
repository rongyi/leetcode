// http://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/description/
#include "xxx.hpp"

class Solution {
public:
  int minimizeTheDifference(vector<vector<int>> &mat, int target) {
    int m = mat.size();
    // int n = mat[0].size();
    // each element is at most 70, so the total sum is m * 70(one num each row)
    vector<vector<int>> dp(m,
                           vector<int>(m * 70 + 1, numeric_limits<int>::max()));

    vector<set<int>> uniq;
    for (auto &row : mat) {
      uniq.push_back(set<int>(row.begin(), row.end()));
    }

    return dfs(uniq, dp, 0, 0, target);
  }

private:
  int dfs(vector<set<int>> &mat, vector<vector<int>> &dp, int cur_row,
          int cur_sum, int target) {
    if (cur_row >= mat.size()) {
      return abs(cur_sum - target);
    }
    if (dp[cur_row][cur_sum] == numeric_limits<int>::max()) {
      // pick one element each row, and choose the min final diff
      for (auto it = mat[cur_row].begin(); it != mat[cur_row].end(); ++it) {
        dp[cur_row][cur_sum] =
            min(dp[cur_row][cur_sum],
                dfs(mat, dp, cur_row + 1, cur_sum + *it, target));

        // if final diff is 0,  then we get the answer and no need to continue
        // or if the cur_sum + *it is already greater than target, then the next
        // one will be bigger, and make the answer is bigger, so no need to
        // continue note the row in mat is sorted!
        if (dp[cur_row][cur_sum] == 0 || cur_sum + *it > target) {
          break;
        }
      }
    }
    return dp[cur_row][cur_sum];
  }
};
