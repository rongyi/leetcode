// https://leetcode.com/problems/count-number-of-special-subsequences/
#include "xxx.h"

class Solution {
public:
  int countSpecialSubsequences(vector<int> &nums) {
    using ll = long long;
    vector<ll> dp(4);
    dp[0] = 1;
    for (auto num : nums) {
      int next_num = num + 1;
      dp[next_num] += (dp[next_num] + dp[next_num - 1]);
      dp[next_num] %= mod_;
    }

    return dp[3];
  }

private:
  static constexpr int mod_ = 1e9 + 7;
};

class SolutionDFS {
public:
  int countSpecialSubsequences(vector<int> &nums) {
    int sz = nums.size();
    vector<vector<long long>> dp(sz, vector<long long>(4, -1));

    return dfs(nums, 0, -1, dp) % mod_;
  }

private:
  int dfs(vector<int> &nums, int cur, int prev, vector<vector<long long>> &dp) {
    if (cur >= nums.size()) {
      if (prev == 2) {
        return 1;
      }
      return 0;
    }
    if (dp[cur][prev + 1] != -1) {
      return dp[cur][prev + 1];
    }
    long long ret = 0;
    // don't pick current
    ret += dfs(nums, cur + 1, prev, dp);
    // pick current but need to satisfy the condition
    if (nums[cur] == prev + 1 || nums[cur] == prev) {
      ret += dfs(nums, cur + 1, nums[cur], dp);
    }
    return dp[cur][prev + 1] = ret % mod_;
  }

private:
  static constexpr int mod_ = 1e9 + 7;
};

