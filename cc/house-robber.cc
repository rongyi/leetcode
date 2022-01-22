// http://leetcode.com/problems/house-robber/description/
#include "xxx.hpp"

class Solution {
public:
  int rob(vector<int> &nums) {
    const int n = nums.size();
    if (nums.empty()) {
      return 0;
    }
    if (n == 1) {
      return nums[0];
    }
    if (n == 2) {
      return max(nums[0], nums[1]);
    }
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(dp[0], nums[1]);
    for (int i = 2; i < n; i++) {
      // 抢了这个节点，最大值就是隔一个的前面的值加上当前值和，前面n - 1的值
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[n - 1];
  }
};

int main() {
  Solution so;

}
