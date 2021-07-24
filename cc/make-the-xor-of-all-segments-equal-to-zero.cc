// http://leetcode.com/problems/make-the-xor-of-all-segments-equal-to-zero/description/
#include "xxx.h"

class Solution {
public:
  // 这里的写作可以说非常好了
  // https://leetcode.com/problems/make-the-xor-of-all-segments-equal-to-zero/discuss/1099112/C%2B%2B-An-easy-solution-with-detailed-explanation-to-a-really-hard-problem
  int minChanges(vector<int> &nums, int k) {
    const int n = nums.size();
    vector<vector<int>> freq(k, vector<int>(1024, 0));
    // dp[i][j] ==> 到位置i为止 xor的值为 j
    // 递推公式是
    // dp[i][j] ==
    // 1. dp[i - 1][j ^ x] when i pos上value为x
    // 2. 当前位置i上需要的改变次数： total - (freq(x) at i)
    vector<vector<int>> dp(k, vector<int>(1024, n + 1));
    unordered_set<int> nums_at_pos[k];

    for (int i = 0; i < n; ++i) {
      int pos = i % k;
      freq[pos][nums[i]]++;
      nums_at_pos[pos].insert(nums[i]);
    }
    int prev_best = 0;

    for (int i = 0; i < k; ++i) {
      // 当前位置的总次数
      int cnt_of_pos = n / k + (i < (n % k) ? 1 : 0);
      int cur_best = n + 1;

      for (int j = 0; j < 1024; ++j) {
        if (i == 0) {
          // 没有i - 1的case
          // 当前位置的总次数 - 已出现的次数 ==> 需要改变的次数
          dp[i][j] = cnt_of_pos - freq[i][j];
        } else {
          // 对于这个位置上出现的num按照递推公式来
          for (auto num : nums_at_pos[i]) {
            dp[i][j] =
                min(dp[i][j], dp[i - 1][j ^ num] + cnt_of_pos - freq[i][num]);
          }

          // 没有出现的，修改次数就是"坑"的个数 加上前一轮的最优解
          dp[i][j] = min(dp[i][j], prev_best + cnt_of_pos);
        }

        cur_best = min(cur_best, dp[i][j]);
      }
      prev_best = cur_best;
    }

    return dp[k - 1][0];
  }
};
