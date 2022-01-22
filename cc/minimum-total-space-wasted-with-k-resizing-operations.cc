// https://leetcode.com/problems/minimum-total-space-wasted-with-k-resizing-operations
#include "xxx.hpp"

class Solution {
public:
  int minSpaceWastedKResizing(vector<int> &nums, int k) {
    int sz = nums.size();
    // dp[i][j] from index (i..n - 1) the need the j cut
    vector<vector<int>> dp(sz, vector<int>(k + 1, -1));

    return dfs(nums, dp, 0, k);
  }
  int dfs(vector<int> &nums, vector<vector<int>> &dp, int cur, int k) {
    if (cur == nums.size()) {
      return 0;
    }
    if (k < 0) {
      return inf;
    }
    if (dp[cur][k] != -1) {
      return dp[cur][k];
    }
    int ret = inf;
    int max_num = nums[cur];
    int interval_sum = 0;
    for (int i = cur; i < nums.size(); ++i) {
      max_num = max(max_num, nums[i]);
      interval_sum += nums[i];
      int wasted = max_num * (i - cur + 1) - interval_sum;
      // next interval start from j + 1
      ret = min(ret, dfs(nums, dp, i + 1, k - 1) + wasted);
    }

    dp[cur][k] = ret;
    return ret;
  }

private:
  static constexpr int inf = 200 * 1e6;
};
int main() {
  Solution so;
  vector<int> input{10, 20};
  so.minSpaceWastedKResizing(input, 0);
}
