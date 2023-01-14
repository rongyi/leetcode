// https://leetcode.com/problems/number-of-great-partitions/
#include "xxx.hpp"

using ll = long long;
class Solution {
public:
  int countPartitions(vector<int> &nums, int k) {
    ll sz = nums.size();
    ll sum = 0;
    for (auto &num : nums) {
      sum += num;
    }
    // not enough
    if (sum < 2 * k || sz == 1) {
      return 0;
    }
    sort(nums.begin(), nums.end());
    vector<vector<ll>> dp(sz, vector<ll>(k, 0));
    for (ll i = 0; i < sz; ++i) {
      for (ll j = 0; j < k; ++j) {
        if (i == 0 && j == 0) {
          dp[i][j] = 1;
          continue;
        }
        if (i == 0) {
          if (j == nums[i]) {
            dp[i][j] = 1;
          }
          continue;
        }

        if (nums[i] > j) {
          // can  not take current
          dp[i][j] = dp[i - 1][j];
        } else {
          // take current or don't take current
          dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
          dp[i][j] %= mod_;
        }
      }
    }
    ll total = modPower(2, sz, mod_);
    ll smallk_ways = 0;
    for (ll i = 1; i < k; ++i) {
      smallk_ways += dp[sz - 1][i];
    }
    smallk_ways %= mod_;

    return (total - smallk_ways * 2 - 2 + mod_) % mod_;
  }

private:
  ll modPower(ll a, ll b, ll mod) {
    if (b == 0) {
      return 1;
    }
    ll ret = modPower(a, b / 2, mod);
    ret = (ret * ret) % mod;
    if (b & 1) {
      ret = (ret * a) % mod;
    }
    return ret;
  }

private:
  ll mod_ = 1e9 + 7;
};
