// http://leetcode.com/problems/burst-balloons/description/
#include "simpleone.h"

class Solution {
public:

  // https://leetcode.com/problems/burst-balloons/discuss/194608/DP-solution-with-detailed-text-and-video-explanation.
  // It may be easier to figure out the recurrence relation by looking at the last step.
  // At the last step, you only have one ballon (3, 1, 5 or 8) to burst, right?
  // So let's have something like opt(END) to denote max coins we can get at the end,
  // we know this opt(END) must come from one of the above 4 cases (by bursting 3, 1, 5 or 8)

  // So it seems like a good idea to use opt(i, j) to represent the max coins we can get from bursting balloons[i, j],
  // let's change opt(END) to opt(i, j) accordingly
  // opt(0, 3) = max(
  // If 3 is the last ballon, this means balloons[1, 5, 8] have been burst already,
  // since we don't know the max coins we got by bursting[1, 5, 8], we'll
  // use opt(1, 3) to denote max coins we can get by bursing balloons from 1 to 3, which is [1, 5, 8]
  //     1 * 3 * 1 + opt(1, 3),
  // Similarily, we have
  //     1 * 1 * 1 + opt(0, 0) + opt(2, 3),
  //     1 * 5 * 1 + opt(0, 1) + opt(3, 3),
  //     1 * 8 * 1 + opt(0, 2)
  // )

  // You may have figured out the recurrence relation from the above equation, if not,
  // let's look at how we'll calculate opt(1, 3)
  // Similar to the above equation,
  // opt(1, 3) = max(
  //     3 * 1 * 1 + opt(2, 3),
  //     3 * 5 * 1 + opt(1, 1) + opt(3, 3),
  //     3 * 8 * 1 + opt(1, 2)
  //     )

  // Thus, we have
  // >> state:
  // opt[i][j] denotes the max coins we can get by bursting balloons[i, j]

  // >> recurrence relationship:
  // for k from i to j
  // max(
  //     // Edge cases are not considered in the below equation!
  //     nums[i - 1] * nums[k] * nums[j + 1] + opt[i][k - 1] + opt[k + 1][j]
  // )

  // 采用的分而治之的方法，主要是上面的递推公式

  int maxCoins(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }
    const int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 0; len < n; len++) {
      for (int i = 0; i + len < n; ++i) {
        int j = i + len;
        for (int k = i; k <= j; ++k) {
          int left_num = (i == 0) ? 1 : nums[i - 1];
          int right_num = (j == n - 1) ? 1 : nums[j + 1];

          int left_dp = (k == i) ? 0 : dp[i][k - 1];
          int right_dp = (k == j) ? 0 : dp[k + 1][j];

          dp[i][j] = max(dp[i][j],
                         left_num * nums[k] * right_num + left_dp + right_dp);
        }
      }
    }
    return dp[0][n - 1];
  }
};
